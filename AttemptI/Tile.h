#ifndef TILE_H
#define TILE_H

#include "SFML\Graphics.hpp"

using namespace std;

class Tile {
private:
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;
	std::string type;
public:
	Tile();
	Tile(std::string name, float x, float y);
	void Draw(sf::RenderWindow &win);
};

#endif