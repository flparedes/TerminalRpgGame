#pragma once

#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Character.h"
#include <iostream>

using namespace std;

class Enemy : public Character
{
public:
	Enemy(const char* name = "Enemy", int iniStr = 5, int iniDex = 5, int iniCons = 5, int iniHp = 10);
	~Enemy();
	int attack(Character &opponent);

	friend ostream& operator<<(ostream &os, const Enemy &enemy);
};

#endif _ENEMY_H_