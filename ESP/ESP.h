#pragma once
#include <windows.h>
#include "Entity.h"
#include "Vector3/Vector3.h"

namespace ESP
{
	namespace Setup
	{
		void SetupImgui(HDC handle);
	}
	namespace Draw
	{
		void shouldDraw();
		void DrawESP(Entity* ent, Vector screen);
	}
}
