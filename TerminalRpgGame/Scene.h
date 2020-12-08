#pragma once

#ifndef _SCENE_H_
#define _SCENE_H_

#include "List.h"
#include "Option.h"
#include "Enemy.h"
#include "Player.h"

// Tipos de escenas: De opciones seleccionable o combate
enum SceneType { OPTIONS = 1, COMBAT };

class Scene
{
private:
	SceneType type;
	char *title;
	char *text;
	int nextScene;
	List<Option> options;
	List<Enemy> enemies;
public:
	Scene(const char* title = "", const char* text = "", const SceneType type = SceneType::OPTIONS);
	Scene(const Scene &sc);
	~Scene();
	void addOption(const Option &opt);
	void addEnemy(const Enemy &enemy);
	int play(Player &player);
	void setNextScene(int nextSc) { nextScene = nextSc; }
	SceneType getType() const { return type; }
private:
	void show();
	int playOptionsScene();
	void showOptions();
	int getOption();
	int playCombatScene(Player &player);
	int selectEnemy();
};

#endif