#pragma once
#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 

#include "BaseScene.h"
#include "Player.h"
#include "NPC.h"
#include <list>
#include "Tile.h"

class GameScene : public BaseScene
{
private:
	Player* player;
	NPC* npc_01;

	list<NPC*> npcs;
	list<Tile*> tiles;
	sf::Music bgSound;
public:
	GameScene();
	
	void Update();
	void Draw(sf::RenderWindow &win);

	GameScene::~GameScene() { };
};

#endif