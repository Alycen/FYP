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
	Player* player;
	NPC* npc_01;
public:
	GameScene();
	
	void Update();
	void UpdateInput(sf::Event event);
	void Draw(sf::RenderWindow &win);

	GameScene::~GameScene() { };
};

#endif