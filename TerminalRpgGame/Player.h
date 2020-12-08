#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"
#include "List.h"
#include "Weapon.h"

class Player :
	public Character
{
private:
	List<Weapon> weapons;
public:
	Player(const char* name = "Player");
	~Player();
	void addWeapon(const Weapon &weapon);
	int attack(Character &opponent);
	const List<Weapon>& getWeapons() const { return weapons; }
};

#endif