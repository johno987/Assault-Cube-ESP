#include "Hook.h"
#include "Setup.h"
#include "imgui.h"
#include "ESP/ESP.h"

BOOL _stdcall MyDetourFunction(HDC HandleToDeviceContext);

using SwapBuffersHook = BOOL(_stdcall*)(HDC HandleToDeviceContext);
//SwapBuffersHook myHook = &MyDetourFunction;
SwapBuffersHook newAddressForExisting = nullptr;

BOOL _stdcall MyDetourFunction(HDC HandleToDeviceContext)
{
	std::cout << "Hooking from inside the swap buffers function\n";
	ESP::Setup::SetupImgui(HandleToDeviceContext);
	ESP::Draw::DrawESP();
	return newAddressForExisting(HandleToDeviceContext);
}

void EnableHook()
{
	auto hookStatus = MH_Initialize();
	if (hookStatus != MH_OK)
	{
		std::cout << "Failed to generate hook " << hookStatus << '\n';
	}

	if (MH_CreateHookApi(L"opengl32.dll", "wglSwapBuffers", &MyDetourFunction, reinterpret_cast<void**>(&newAddressForExisting)))
	{
		std::cout << "Failed to make the hook into the swap buffers function, perhaps failed address\n";
	}
	else
	{
		std::cout << "Hook active!\n";
		MH_EnableHook(MH_ALL_HOOKS);
	}

}

void DisableHook()
{
	std::cout << "Disabling the swap buffers hook\n";
	MH_DisableHook(MH_ALL_HOOKS);
	newAddressForExisting = nullptr;
	MH_Uninitialize();
}