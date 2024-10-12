#pragma once
#include <cstdint>
#include <algorithm>

struct Vector3
{
	float x;
	float y;
	float z;
};

class Entity
{
public:
	char pad_0000[4]; //0x0000
	Vector3 HeadPos; //0x0004
	char pad_0010[36]; //0x0010
	Vector3 FeetPos; //0x0034
	char pad_0040[184]; //0x0040
	int32_t Health; //0x00F8
	char pad_00FC[852]; //0x00FC
}; //Size: 0x0450
//static_assert(sizeof(Entity) == 0x450);

class EntityList
{
public:
	Entity* entities[64]; //an array of entites within the game
	void printEntLocations();
};