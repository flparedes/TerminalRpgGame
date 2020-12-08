#include "Player.h"
#include <stdlib.h>     /* srand, rand */
#include <iostream>

using namespace std;

Player::Player(const char* name) : Character(name)
{
}


Player::~Player()
{
}


void Player::addWeapon(const Weapon &weapon) {
	weapons.add(weapon);
}


int Player::attack(Character &opponent) {
	int damage = 0;
	int wpnIndex = -1;

	// 1 - Elegir arma
	do {
		cout << "Elegir arma: " << endl;
		for (int i = 0; i < weapons.getSize(); i++) {
			cout << (i + 1) << " - " << weapons.get(i) << endl;
		}
		cin >> wpnIndex;
		wpnIndex--;
	} while (wpnIndex < 0 && wpnIndex >= weapons.getSize());

	// 2 - En función del tipo de arma el modificador del ataque varía
	int attackMod = 0;
	Weapon &weapon = weapons.get(wpnIndex);
	switch (weapon.getType())
	{
		case WeaponType::STRENGTH:
			attackMod = this->str;
			break;
		case WeaponType::DEXTERITY:
			attackMod = this->dex;
			break;
		default:
			break;
	}

	// 3 - Hacer una "tirada" para ver si el ataque surte efecto
	int attack = (rand() % 10 + 1) + attackMod;
	int defense = (rand() % 10 + 1) + opponent.getDex();

	// 4 - Mostrar la info del ataque
	cout << this->name << " ataca con su " << weapon << " con " << attack << endl;
	cout << opponent.getName() << " se defiende con " << defense << endl;

	// 5 - Si el ataque impacta se calcula el daño en función del arma usada
	if (attack >= defense) {
		// El daño es una "tirada" de daño del arma más el modificador del ataque
		damage = (rand() % weapon.getDamage() + 1) + attackMod;
		cout << opponent.getName() << " recibe " << damage << " puntos de daño." << endl << endl;
	}
	else {
		cout << opponent.getName() << " esquiva el ataque." << endl << endl;
	}

	return damage;
}
