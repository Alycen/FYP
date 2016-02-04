#include "GameScene.h"
const int MAP_W = 29;
const int MAP_H = 15;

GameScene::GameScene() {
	if (!bgSound.openFromFile("Assets/Sounds/backGround.ogg"))
		// handle error
		int i = 0;
	bgSound.setVolume(25);
	bgSound.play();
	player = new Player(900.0f, 200.0f);
	npc_01 = new NPC(600.f, 500.0f);

	Camera::GetInstance()->Init(650, 500);
	Camera::GetInstance()->setCentre(player->GetPosition());

	long map[MAP_W * MAP_H] = {
		3,0,0,0,0,0,0,1,3,3,0,1,1,0,0,0,1,2,0,0,0,0,0,0,0,3,3,3,0,
		3,0,1,0,3,0,0,3,3,3,0,0,1,0,0,1,1,2,0,0,0,0,0,0,3,3,3,3,3,
		3,0,0,0,0,3,3,3,0,0,0,1,0,0,1,0,1,2,0,0,0,0,3,0,3,3,3,3,0,
		3,0,1,0,0,0,1,3,0,1,0,0,0,0,1,1,1,2,0,0,1,0,0,3,3,3,0,3,3,
		3,0,1,0,0,0,3,0,1,1,0,0,1,3,3,1,1,0,2,0,0,0,1,0,0,0,0,3,0,
		3,0,0,0,3,3,1,0,0,0,0,1,1,3,3,3,1,0,0,2,0,1,1,0,0,1,0,1,0,
		3,0,0,0,3,0,1,0,0,1,0,0,0,1,3,1,0,0,0,0,2,2,2,2,2,2,2,2,2,
		3,0,0,3,3,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,1,1,1,0,1,0,0,0,1,
		3,0,0,0,0,0,0,1,3,3,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,3,3,3,0,
		3,0,1,0,3,0,0,3,3,3,0,0,1,0,0,1,1,0,0,0,0,0,0,0,3,3,3,3,3,
		3,0,0,0,0,3,3,3,0,0,0,1,0,0,1,0,1,1,0,0,0,0,3,0,3,3,3,3,0,
		3,0,1,0,0,0,1,3,0,1,0,0,0,0,1,1,1,0,0,0,1,0,0,3,3,3,0,3,3,
		3,0,1,0,0,0,3,0,1,1,0,0,1,3,3,1,1,0,0,0,0,0,1,0,0,0,0,3,0,
		3,0,0,0,3,3,1,0,0,0,0,1,1,3,3,3,1,0,0,1,0,1,1,0,0,1,0,1,0,
		3,0,0,0,3,0,1,0,0,1,0,0,0,1,3,1,0,0,0,0,0,0,1,1,0,1,0,0,0,
	};

	int x, y;
	int count = 0;
	for (y = 0; y < MAP_H; y++) {
		for (x = 0; x < MAP_W; x++) {
			if (map[count] == 0) {
				tiles.push_back(new Tile("grass", 60 * x, 60 * y));
			}
			else if (map[count] == 1) {
				tiles.push_back(new Tile("soil", 60 * x, 60 * y));
			}
			else if (map[count] == 2) {
				tiles.push_back(new Tile("path", 60 * x, 60 * y));
			}
			else if (map[count] == 3) {
				tiles.push_back(new Tile("water", 60 * x, 60 * y));
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