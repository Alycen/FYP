#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#include "ResourceManager.h"

class Player
{
private:
	ResourceManager rm; // All assets will be loaded and set through AN INSTANCE of ResourceManager

	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2f position;
	sf::Vector2f velocity;
	float xScale = 0.3f;
	float yScale = 0.3f;
	float vSpeed = 0.03f;
	float hSpeed = 0.01f;

	bool left = false, right = false, up = false, down = false;

public:
	Player();
	Player(float x, float y);

	void Update();
	void Draw(sf::RenderWindow &win);

	void Move(int dir);
	void isRunning(bool r);

	Player::~Player() {};
};

#endif