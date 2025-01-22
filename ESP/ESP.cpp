#include "ESP.h"
#include <windows.h>
#include "imgui.h"
#include <iostream>
#include "imgui_impl_opengl3.h"
#include "glew/glew-2.1.0/include/GL/glew.h"
#include <string>
#include "ESPV2/ESPV2.h"
#include "Vector3/Vector3.h"

static bool ImGuiInitialised = false;

bool worldToScreen(Vector pos, Vector& screen, float matrix[16], int windowWidth, int windowHeight)
{
	Vector4 clipCoordinates{};

	clipCoordinates.x = pos.x * matrix[0] + pos.y * matrix[4] + pos.z * matrix[8] + matrix[12];
	clipCoordinates.y = pos.x * matrix[1] + pos.y * matrix[5] + pos.z * matrix[9] + matrix[13];
	clipCoordinates.z = pos.x * matrix[2] + pos.y * matrix[6] + pos.z * matrix[10] + matrix[14];
	clipCoordinates.w = pos.x * matrix[3] + pos.y * matrix[7] + pos.z * matrix[11] + matrix[15];

	if (clipCoordinates.w < 0.1f)
	{
		return false; //bot behind you so dont draw
	}

	Vector NDC{};
	NDC.x = clipCoordinates.x / clipCoordinates.w;
	NDC.y = clipCoordinates.y / clipCoordinates.w;
	NDC.z = clipCoordinates.z / clipCoordinates.w;

	//new NDC mapping calcs
	screen.x = (NDC.x + 1.0f) * (windowWidth / 2.0f);
	screen.y = (1.0f - NDC.y) * (windowHeight / 2.0f);

	//old NDC calcs
	/*screen.x = (windowWidth / 2 * NDC.x) + (NDC.x + windowWidth / 2);
	screen.y = (windowHeight / 2 * NDC.y) + (NDC.y + windowHeight / 2);*/

	return true;
}

void ESP::Setup::SetupImgui(HDC Handle)
{
	if (ImGuiInitialised)
		return;

	HGLRC currentContext = wglGetCurrentContext();
	HDC currentDC = wglGetCurrentDC();

	if (!currentContext || !currentDC)
	{
		std::cout << "Failed to initialise the current context\n";
	}

	if (!wglMakeCurrent(currentDC, currentContext))
	{
		std::cout << "Failed to activate the OpenGL Context\n";
	}

	if (!ImGuiInitialised)
	{
		HWND hwnd = WindowFromDC(Handle);
		if (hwnd)
		{
			IMGUI_CHECKVERSION();
			ImGui::CreateContext();
			ImGui_ImplOpenGL3_Init("#version 330");
			ImGuiInitialised = true;
		}
	}

}

void ESP::Draw::DrawESP(Entity* ent, Vector Screen)
{
	//yse screen coords to draw position x and y 

	ImVec2 BotPosition = ImVec2(Screen.x, Screen.y);
	ImVec2 baseOfScreen = ImVec2(950.0f / 2, 750);

	float boxWidth = 50.0f;
	float boxHeight = 100.0f;

	ImVec2 rect_min = ImVec2(BotPosition.x - boxWidth / 2, BotPosition.y - boxHeight / 2); //top left
	ImVec2 rect_max = ImVec2(BotPosition.x + boxWidth / 2, BotPosition.y + boxHeight / 2); //bottom right

	//get the viewport size
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	float width = static_cast<float>(viewport[2]);
	float height = static_cast<float>(viewport[3]);

	//set the imGui display size manually
	ImGuiIO& io = ImGui::GetIO();
	io.DisplaySize = ImVec2(width, height);
	ImGui_ImplOpenGL3_NewFrame();
	ImGui::NewFrame();

	ImDrawList* draw_list = ImGui::GetForegroundDrawList();
	//ImVec2 rect_min = ImVec2(100, 100); //top left corner
	//ImVec2 rect_max = ImVec2(300, 200); //bottom right corner

	ImU32 colour = IM_COL32(255, 0, 0, 255);
	float thickness = 2.0f;

	//draw_list->AddRect(rect_min, rect_max, colour, 0.0f, 0, thickness);

	//ImVec2 LineMin = ImVec2(viewport[2] / 2, viewport[3]); //top left corner
	//ImVec2 LineMax = ImVec2(viewport[2] / 2, 0); //bottom right corner

	//ImU32 Linecolour = IM_COL32(150, 0, 0, 255);
	//draw_list->AddLine(LineMin, LineMax, Linecolour);

	//ImVec2 Centre = ImVec2(viewport[2] / 2, viewport[3] / 2);
	// 
	//draw_list->AddCircle(BotPosition, 50.0f, colour);
	draw_list->AddRect(rect_min, rect_max, colour);
	draw_list->AddLine(baseOfScreen, BotPosition, colour);
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

}

	

void ESP::Draw::shouldDraw()
{
	for (int i{}; i < *maxNumbersOfPlayers; ++i)
	{
		if (entList->entities[i] != nullptr)
		{
			Vector screenCoords{};
			Entity* entity = entList->entities[i];
			if (isEnemy(entity) && isAlive(entity))
			{
				if (worldToScreen(entity->HeadPos, screenCoords, matrix, 950, 750))
				{
					ESP::Draw::DrawESP(entity, screenCoords);
				}
				
			}
		}
	}
}