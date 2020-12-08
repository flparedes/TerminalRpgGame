#pragma once

#ifndef _GAME_H_
#define _GAME_H_

#include "List.h"
#include "Scene.h"
#include "Player.h"

class Game
{
private:
	List<Scene> scenes;
	int currentSceneIndex = 0;
	Player player;
public:
	Game(const Player &player);
	~Game();
	void addScene(const Scene &sc);
	void run();
};

#endif