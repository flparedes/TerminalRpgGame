#include "Enemy.h"
#include <stdlib.h>     /* srand, rand */
#include <iostream>

using namespace std;

Enemy::Enemy(const char* name, int iniStr, int iniDex, int iniCons, int iniHp) : 
	Character(name, iniStr, iniDex, iniCons, iniHp)
{
}


Enemy::~Enemy()
{
}


int Enemy::attack(Character &opponent) {
	int damage = 0;

	// 1 - Hacer una "tirada" para ver si el ataque surte efecto
	int attack = (rand() % 10 + 1) + this->dex;
	int defense = (rand() % 10 + 1) + opponent.getDex();

	// 3 - Mostrar la info del ataque
	cout << this->name << " ataca con " << attack << endl;
	cout << opponent.getName() << " se defiende con " << defense << endl;

	// 2 - Si el ataque impacta se calcula el daño en función del arma usada
	if (attack >= defense) {
		// Incluir el daño del arma, de momento supondremos un random de 5
		damage = (rand() % 5 + 1) + this->str;
		cout << opponent.getName() << " recibe " << damage << " puntos de daño." << endl << endl;
	}
	else {
		cout << opponent.getName() << " esquiva el ataque." << endl << endl;
	}

	return damage;
}


ostream& operator<<(ostream &os, const Enemy &enemy) {
	os << enemy.name << "(hp: " << enemy.hp << ")";
	return os;
}