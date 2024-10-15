// dllmain.cpp : Defines the entry point for the DLL application.
#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include "Globals.h"
#include <algorithm>
#include "Entity.h"
#include "Setup.h"
#include "MinHook.h"
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include "imgui.h"
//#include "imgui_impl_glfw.h"
//#include "imgui_impl_opengl3.h"



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
			SetupImgui();
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

