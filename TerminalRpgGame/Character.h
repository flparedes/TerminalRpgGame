#pragma once

#ifndef _CHARACTER_H_
#define _CHARACTER_H_

class Character
{
protected:
	char *name;
	int str;
	int dex;
	int cons;
	int hp;
public:
	Character(const char* name = "", int iniStr = 5, int iniDex = 5, int iniCons = 5, int iniHp = 10);
	~Character();

	const char* getName() const { return name; };
	const int getStr() const { return str; };
	const int getDex() const { return dex; };
	const int getCons() const { return cons; };
	const int getHp() const { return hp; };

	void showStats();
	virtual int attack(Character &opponent) = 0;
	virtual void receiveDamage(int damage);
	bool isDead() const { return hp <= 0; };
};

#endif