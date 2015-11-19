#pragma once
#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "BaseScene.h"
#include "Player.h"
#include "NPC.h"
//#include "SFML\Graphics.hpp"

class GameScene : public BaseScene
{
private:
	Player player;
	NPC npc_01;
public:
	GameScene();
	~GameScene();
};

#endif