#include "ESP.h"
#include <windows.h>
#include "imgui.h"
#include <iostream>
#include "imgui_impl_opengl3.h"
#include "glew/glew-2.1.0/include/GL/glew.h"

static bool ImGuiInitialised = false;
static GLint viewport[4];

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

void ESP::Draw::DrawESP()
{
	//get the viewport size
	//GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	float width = static_cast<float>(viewport[2]);
	float height = static_cast<float>(viewport[3]);

	//set the imGui display size manually
	ImGuiIO& io = ImGui::GetIO();
	io.DisplaySize = ImVec2(width, height);
	ImGui_ImplOpenGL3_NewFrame();
	ImGui::NewFrame();

	ImDrawList* draw_list = ImGui::GetForegroundDrawList();
	ImVec2 rect_min = ImVec2(100, 100); //top left corner
	ImVec2 rect_max = ImVec2(300, 200); //bottom right corner

	ImU32 colour = IM_COL32(255, 0, 0, 255);
	float thickness = 2.0f;

	draw_list->AddRect(rect_min, rect_max, colour, 0.0f, 0, thickness);

	ImVec2 LineMin = ImVec2(viewport[2] / 2, viewport[3]); //top left corner
	ImVec2 LineMax = ImVec2(viewport[2] / 2, 0); //bottom right corner

	ImU32 Linecolour = IM_COL32(150, 0, 0, 255);
	draw_list->AddLine(LineMin, LineMax, Linecolour);

	ImVec2 Centre = ImVec2(viewport[2] / 2, viewport[3] / 2);
	draw_list->AddCircle(Centre, 100.0f, Linecolour);

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
