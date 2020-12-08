#include "Scene.h"
#include "string.h"
#include "List.h"
#include <iostream>
#include "Player.h"

using namespace std;

Scene::Scene(const char* title, const char* text, const SceneType type): nextScene(-1)
{
	this->title = _strdup(title);
	this->text = _strdup(text);
	this->type = type;
}


Scene::Scene(const Scene &sc)
{
	this->title = _strdup(sc.title);
	this->text = _strdup(sc.text);
	this->options = *sc.options.clone();
	this->nextScene = sc.nextScene;
}


Scene::~Scene()
{
	delete[] title;
	delete[] text;
}


void Scene::addOption(const Option &opt) {
	if (type != SceneType::OPTIONS) {
		cout << "No se pueden añadir opciones a este tipo de escena";
	}
	else {
		options.add(opt);
	}
}


void Scene::addEnemy(const Enemy &enemy) {
	if (type != SceneType::COMBAT) {
		cout << "No se pueden añadir enemigos a este tipo de escena";
	}
	else {
		enemies.add(enemy);
	}
}


void Scene::show() {
	cout << text << endl;
}


void Scene::showOptions() {
	for (int i = 0; i < options.getSize(); i++) {
		cout << (i + 1) << " - " << options.get(i).getText() << endl;
	}
}


int Scene::getOption() {
	int opt;
	cin >> opt;

	return --opt;
}


int Scene::play(Player &player) {
	switch (type)
	{
	case SceneType::OPTIONS:
		return playOptionsScene();
		break;
	case SceneType::COMBAT:
		return playCombatScene(player);
		break;
	default:
		break;
	}

	// Si no es de ningun tipo anterior pasar directamente a la siguiente escena
	return nextScene;
}

int Scene::playOptionsScene() {
	int selOption = -1;

	do {
		// 1.- Mostrar el texto
		show();

		// 2.- Mostrar las opciones
		showOptions();

		// 3.- Obtener opción seleccionada
		selOption = getOption();

	} while (selOption < 0 || selOption >= options.getSize());
	
	// 4.- Resolver opción (Pendiente)

	// 5.- Pasar a la siguiente escena
	return nextScene;
}


int Scene::playCombatScene(Player &player) {
	bool inCombat = true;
	int deadEnemies;

	// 1.- Mostrar el texto
	show();

	do {
		deadEnemies = 0;

		// De momento no vamos a permitir huir del combate

		// 2.- Seleccionar enemigo
		int enemySelected = selectEnemy();

		// 3.- Atacar al enemigo
		Enemy *enemy = &enemies.get(enemySelected);
		enemy->receiveDamage(player.attack(*enemy));

		// 4.- Ahora atacan los enemigos (si siguen vivos)
		for (int i = 0; i < enemies.getSize(); i++) {
			enemy = &enemies.get(i);
			if (enemy->isDead()) {
				deadEnemies++;
			}
			else {
				player.receiveDamage(enemy->attack(player));
			}
		}

		// 5.- Comprobar si el combate sigue
		inCombat = deadEnemies < enemies.getSize() && !player.isDead();
	} while (inCombat);

	// 5.- Pasar a la siguiente escena
	return nextScene;
}

int Scene::selectEnemy() {
	int enemySelected = -1;
	do {
		cout << "Selecciona a que enemigo atacar" << endl;
		for (int i = 0; i < enemies.getSize(); i++) {
			cout << (i + 1) << " - " << enemies.get(i) << endl;
		}

		cin >> enemySelected;
		enemySelected--;
	} while (enemySelected < 0 || enemySelected >= enemies.getSize());

	return enemySelected;
}
