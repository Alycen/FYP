#include "GameScene.h"
const int MAP_W = 10;
const int MAP_H = 10;

GameScene::GameScene() {
	player = new Player(900.0f, 200.0f);
	npc_01 = new NPC(600.f, 500.0f);

	int map[MAP_W * MAP_H] = {
		3,0,0,0,0,
		3,2,1,0,3,
		3,2,1,0,3,
		3,2,1,0,3,
		3,2,1,0,3
	};

	int x, y;
	for (y = 0; y < MAP_H; y++) {
		for (x = 0; x < MAP_W; x++) {
			if (map[x,y] == 0) {
				tiles.push_back(new Tile("grass", 64 * x, 64 * y));
			}
			else if (map[x, y] == 1) {
				tiles.push_back(new Tile("soil", 64 * x, 64 * y));
			}
			else if (map[x, y] == 2) {
				tiles.push_back(new Tile("path", 64 * x, 64 * y));
			}
			else if (map[x, y] == 3) {
				tiles.push_back(new Tile("water", 64 * x, 64 * y));
			}
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