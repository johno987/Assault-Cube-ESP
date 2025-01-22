#pragma once
#include "Vector3/Vector3.h"
#include <string>
#include "Entity.h"
#include "Globals.h"

//inline Entity* LocalPlayer{};
//inline EntList* EntityList{};
//const int maxPlayers = 12;
//inline float matrix[16];
//
//class Entity
//{
//public:
//	void* VTablePointer;
//	int health;
//	Vector3 HeadPosition;
//	Vector3 FootPositon;
//	const char* name;
//	int TeamNumber;
//
//};

//class EntList
//{
//public:
//	Entity* Entities[64];
//};

bool isEnemy(Entity* ent)
{
	//removed the team number check, doesnt seem to be valid for free for all
	if (strncmp(ent->Name, LocalPlayer->Name, 16) != 0)
	{
		return true;
	}

	//if (ent->TeamNumber != LocalPlayer->TeamNumber)
	//	return true;
	return false;
}

bool isAlive(Entity* ent)
{
	if (ent->Health > 0)
		return true;
	return false;
}

void DrawESP(Entity* ent)
{
	//do all the rendering in here
	//render the box
	//render the text for the name
	std::string Name = ent->Name;

	//once this is done, we can call render and renderstate
	//go back to the hooked function from here and return the original swap buffers

}

void GetPotentialRenders()
{
	for (int i{}; i < *maxNumbersOfPlayers; ++i)
	{
		if (entList->entities[i] != nullptr)
		{
			Entity* entity = entList->entities[i];
			if (isEnemy(entity) && isAlive(entity))
			{
				DrawESP(entity);
			}
		}
	}
}