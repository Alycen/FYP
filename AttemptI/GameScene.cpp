#include "GameScene.h"

GameScene::GameScene() {
	player = new Player(900.0f, 200.0f);
	npc_01 = new NPC(600.f, 500.0f);
}

void GameScene::Update() {
	player->Update();
	npc_01->Update();
}


void GameScene::Draw(sf::RenderWindow &win) {
	player->Draw(win);
	npc_01->Draw(win);
}