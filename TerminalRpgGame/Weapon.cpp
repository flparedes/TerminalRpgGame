#include "Weapon.h"
#include <string.h>
#include <iostream>

using namespace std;

Weapon::Weapon(WeaponType type, const char* name, int damage)
{
	this->type = type;
	this->name = _strdup(name);
	this->damage = damage;
}


Weapon::~Weapon()
{
	delete[] name;
}

ostream& operator<<(ostream &os, const Weapon &wpn) {
	os << wpn.name;
	return os;
}
