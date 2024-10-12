#pragma once
#include <windows.h>
#include "Entity.h"

inline uintptr_t ModuleBase = reinterpret_cast<uintptr_t>(GetModuleHandle(L"ac_client.exe"));
inline auto LocalPlayer = *reinterpret_cast<Entity**>(ModuleBase + 0x10f4f4); //unsure if pointer is correct here
inline auto entList = *reinterpret_cast<EntityList**>(ModuleBase + 0x10f4f8); 
inline FILE* file = NULL; //pointer to the console so we can print using fprintf