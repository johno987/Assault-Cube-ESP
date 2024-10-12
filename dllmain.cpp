// dllmain.cpp : Defines the entry point for the DLL application.
#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include "Globals.h"
#include <algorithm>
#include "Entity.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

void glfw_error_callback(int error, const char* description) 
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int ImGuiCode()
{
    // Initialize GLFW
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return -1;

    // Setup OpenGL context version (here we're using 3.3)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(1280, 720, "ImGui Example", NULL, NULL);
    if (window == NULL)
        return -1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Initialize GLEW to manage OpenGL extensions
    if (glewInit() != GLEW_OK)
        return -1;

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // Start ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Create a simple ImGui window
        {
            ImGui::Begin("Hello, world!");
            ImGui::Text("This is some text.");
            ImGui::SliderFloat("Float", &io.DeltaTime, 0.0f, 1.0f);
            ImGui::End();
        }

        // Render ImGui
        ImGui::Render();
        glViewport(0, 0, 1280, 720);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap buffers
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

void SpawnConsole()
{
	AllocConsole();
	freopen_s(&file, "CONOUT$", "w", stdout);
	std::cout << "Is this console working?\n";
}
DWORD MainHackThread(HMODULE hmodule)
{
	//Spawn the console
	SpawnConsole();

	//execution loop
	while (true)
	{
		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			//Set health to 5000
			std::cout << "Health set to 5000\n";
			LocalPlayer->Health = 5000;
		}
		if (GetAsyncKeyState(VK_HOME) & 1)
		{
			//entList->printEntLocations();
            ImGuiCode();
		}
		if (GetAsyncKeyState(VK_END) & 1)
		{
			break;
		}
	}

	fclose(file);
	FreeConsole();
	FreeLibraryAndExitThread(hmodule, 0);

	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		auto Handle = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainHackThread, hModule, 0, nullptr);
		CloseHandle(Handle);
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

