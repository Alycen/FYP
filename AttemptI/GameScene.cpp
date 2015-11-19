#include "GameScene.h"

GameScene::GameScene() {
	Player player = Player(900.0f, 200.0f);
	NPC npc_01 = NPC(600.f, 500.0f);
}

GameScene::~GameScene() { }