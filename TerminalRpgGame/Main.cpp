#include <iostream>
#include "Game.h"
#include "Scene.h"
#include "Option.h"
#include <time.h>

using namespace std;

Game& initGame();

int main(int argc, char *argv[]) {
	char status = '\0';
	cout << "Bienvenido a Terminal RPG Game, un juego de rol en la terminal de consola." << endl;

	/* initialize random seed: */
	srand(time(NULL));

	Game game = initGame();
	game.run();

	system("PAUSE");
	return EXIT_SUCCESS;
}

Game& initGame() {
	Game *game;

	// Inicializar al jugador
	Player *player = new Player();
	Weapon *weapon = new Weapon();
	player->addWeapon(*weapon);
	weapon = new Weapon(WeaponType::DEXTERITY, "Arco", 6);
	player->addWeapon(*weapon);
	game = new Game(*player);

	// TODO - Inicializar el juego (escenarios, personajes, armas, enemigos, etc.)
	Scene *sc1 = new Scene("Prueba", "Esta es una escena de prueba");
	sc1->setNextScene(1);

	Option *op1 = new Option("OP1");
	Option *op2 = new Option("OP2");
	sc1->addOption(*op1);
	sc1->addOption(*op2);

	game->addScene(*sc1);

	Scene *sc2 = new Scene("SC2", "Esta es la segunda escena escena de pruebas");
	sc2->setNextScene(2);

	op1 = new Option("OP2-1");
	op2 = new Option("OP2-2");
	sc2->addOption(*op1);
	sc2->addOption(*op2);

	game->addScene(*sc2);

	// Una escena de combate
	Scene *sc3 = new Scene("SC3", "Aparecen dos Goblins que se interponen en tu camino, toca pelear.", SceneType::COMBAT);
	sc3->setNextScene(-1); // Última escena

	Enemy *enemy = new Enemy("Goblin 1", 3, 3, 2, 5);
	sc3->addEnemy(*enemy);
	enemy = new Enemy("Goblin 2", 3, 3, 2, 5);
	sc3->addEnemy(*enemy);

	game->addScene(*sc3);

	return *game;
}
