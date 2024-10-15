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

// Created with ReClass.NET 1.2 by KN4CK3R

//class Entity
//{
//public:
//	Vector3 HeadPos; //0x0004
//	char pad_0010[36]; //0x0010
//	Vector3 FeetPos; //0x0034
//	Vector2 ViewAngles; //0x0040
//	char pad_0048[176]; //0x0048
//	int32_t Health; //0x00F8
//	int32_t Armour; //0x00FC
//	char pad_0100[293]; //0x0100
//	char Name[16]; //0x0225
//	char pad_0235[247]; //0x0235
//	int32_t TeamNumber; //0x032C
//	char pad_0330[68]; //0x0330
//	class Weapon* CurrentWeapon; //0x0374
//
//	virtual void Function0();
//	virtual void Function1();
//	virtual void Function2();
//	virtual void Function3();
//	virtual void Function4();
//	virtual void Function5();
//	virtual void Function6();
//	virtual void Function7();
//	virtual void Function8();
//	virtual void Function9();
//}; //Size: 0x0378
//static_assert(sizeof(Entity) == 0x378);
//
//class Weapon
//{
//public:
//	char pad_0000[16]; //0x0000
//	class MagazineAmmo* Magazine; //0x0010
//	class Ammo* Gun; //0x0014
//}; //Size: 0x0018
//static_assert(sizeof(Weapon) == 0x18);
//
//class Ammo
//{
//public:
//	int32_t CurrentAmmo; //0x0000
//}; //Size: 0x0004
//static_assert(sizeof(Ammo) == 0x4);
//
//class MagazineAmmo
//{
//public:
//	int32_t Ammo; //0x0000
//	char pad_0004[36]; //0x0004
//	int32_t MagazineSize; //0x0028
//}; //Size: 0x002C
//static_assert(sizeof(MagazineAmmo) == 0x2C);