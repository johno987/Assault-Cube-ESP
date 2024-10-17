#pragma once
#include <iostream>
#include "MinHook.h"
#include "Globals.h"

BOOL _stdcall MyDetourFunction(HDC HandleToDeviceContext);

void EnableHook();

void DisableHook();
