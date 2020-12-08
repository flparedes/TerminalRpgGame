#include "Character.h"
#include <iostream>
#include <string.h>

using namespace std;

Character::Character(const char* name, int iniStr, int iniDex, int iniCons, int iniHp):
	str(iniStr), dex(iniDex), cons(iniCons), hp(iniHp)
{
	this->name = _strdup(name);
}


Character::~Character()
{
	delete[] name;
}


void Character::showStats() {
	cout << name << " stats:" << endl;
	cout << "Fuerza (str): " << str << endl;
	cout << "Destreza (dex): " << str << endl;
	cout << "Constitucion (cons): " << str << endl;
}


void Character::receiveDamage(int damage) {
	this->hp -= damage;
	if (hp <= 0) {
		cout << name << " ha sido derrotado." << endl;
	}
}
