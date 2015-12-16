#include "Tile.h"

Tile::Tile() { }

Tile::Tile(std::string name, float x, float y) {
	if (name == "soil") {
		texture.loadFromFile("Assets/tiles/soil.png");
	}
	else if (name == "water") {
		texture.loadFromFile("Assets/tiles/water.png");
	}
	else if (name == "grass") {
		texture.loadFromFile("Assets/tiles/grass.png");
	}
	else if (name == "path") {
		texture.loadFromFile("Assets/tiles/path.png");
	}
	texture.setSmooth(true);

	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}

void Tile::Draw(sf::RenderWindow &win) {
	win.draw(sprite);
}