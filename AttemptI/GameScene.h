#pragma once
#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 

#include "BaseScene.h"
#include "Player.h"
#include "NPC.h"
#include <list>

class GameScene : public BaseScene
{
private:
	Player* player;
	NPC* npc_01;
	list<NPC*> npcs;
public:
	GameScene();
	
	void Update();
	void Draw(sf::RenderWindow &win);

	GameScene::~GameScene() { };
};

#endif