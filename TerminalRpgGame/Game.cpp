#include "Game.h"
#include "Player.h"

Game::Game(const Player &player)
{
	this->player = player;
}


Game::~Game()
{
}


void Game::addScene(const Scene &sc) {
	scenes.add(sc);
}


void Game::run() {
	do {
		Scene &currentScene = scenes.get(currentSceneIndex);
		currentSceneIndex = currentScene.play(player);
	} while (currentSceneIndex >= 0);
}