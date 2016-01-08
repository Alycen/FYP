#include "Tile.h"

Tile::Tile() { }

Tile::Tile(std::string name, float x, float y) {
	type = name;
	if (type == "soil") {
		texture.loadFromFile("Assets/tiles/soil_d.png");
	}
	else if (type == "water") {
		texture.loadFromFile("Assets/tiles/water_d.png");
	}
	else if (type == "grass") {
		texture.loadFromFile("Assets/tiles/grass_d.png");
	}
	else if (type == "path") {
		texture.loadFromFile("Assets/tiles/path_d.png");
	}
	texture.setSmooth(true);

	position = sf::Vector2f(x, y);

	sprite.setTexture(texture);
	sprite.setPosition(position.x, position.y);
}

void Tile::Draw(sf::RenderWindow &win) {
	win.draw(sprite);
}