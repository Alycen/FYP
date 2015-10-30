#pragma once
#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "BaseScene.h"
#include "Player.h"
#include "NPC.h"

class GameScene : public BaseScene
{
private:
	Player player;
	NPC npc_01;
public:

};

#endif