#include "GameScene.h"
const int MAP_W = 18;
const int MAP_H = 8;

GameScene::GameScene() {
	player = new Player(900.0f, 200.0f);
	npc_01 = new NPC(600.f, 500.0f);

	int map[MAP_W * MAP_H] = {
		3,0,0,0,0,0,0,1,3,3,0,1,1,0,0,0,1,2,
		3,0,1,0,3,0,0,3,3,3,0,0,1,0,0,1,1,2,
		3,0,0,0,0,3,3,3,0,0,0,1,0,0,1,0,1,1,
		3,0,1,0,0,0,1,3,0,1,0,0,0,0,1,1,1,2,
		3,0,1,0,0,0,3,0,1,1,0,0,1,3,3,1,1,0,
		3,0,0,0,3,3,1,0,0,0,0,1,1,3,3,3,1,0,
		3,0,0,0,3,0,1,0,0,1,0,0,0,1,3,1,0,0,
		3,0,0,3,3,0,0,0,1,0,0,0,0,0,0,1,1,0,
	};

	int x, y;
	int count = 0;
	for (y = 0; y < MAP_H; y++) {
		for (x = 0; x < MAP_W; x++) {
			if (map[count] == 0) {
				tiles.push_back(new Tile("grass", 58 * x, 58 * y));
			}
			else if (map[count] == 1) {
				tiles.push_back(new Tile("soil", 58 * x, 58 * y));
			}
			else if (map[count] == 2) {
				tiles.push_back(new Tile("path", 58 * x, 58 * y));
			}
			else if (map[count] == 3) {
				tiles.push_back(new Tile("water", 58 * x, 58 * y));
			}
			count++;
		}
	}
}

void GameScene::Update() {
	player->Update();
	npc_01->Update();
}

void GameScene::Draw(sf::RenderWindow &win) {
	for each (Tile* t in tiles) {
		t->Draw(win);
	}
	player->Draw(win);
	npc_01->Draw(win);
}