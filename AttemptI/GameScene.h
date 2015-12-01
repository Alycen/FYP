#pragma once
#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 

#include "BaseScene.h"
#include "Player.h"
#include "NPC.h"

class GameScene : public BaseScene
{
private:
	NPC* npc_01;
public:
	sf::RenderWindow *window;//(sf::VideoMode(1200, 800, 32), "Project Mk 1");
	Player* player;
	GameScene();
	void PlayerControl(int dir);
	void Update();
	void Draw(sf::RenderWindow &win);

	GameScene::~GameScene() { };
};

#endif