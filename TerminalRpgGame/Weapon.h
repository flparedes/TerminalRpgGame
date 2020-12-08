#pragma once

#ifndef _WEAPON_H_
#define _WEAPON_H_

#include <iostream>

using namespace std;

enum WeaponType { STRENGTH = 1, DEXTERITY};

class Weapon
{
private:
	WeaponType type;
	char* name;
	int damage;
public:
	Weapon(WeaponType type = STRENGTH, const char* name = "Sword", int damage = 4);
	~Weapon();
	WeaponType getType() { return type; };
	int getDamage() { return damage; };
	friend ostream& operator<<(ostream &os, const Weapon &wpn);
};

#endif