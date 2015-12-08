#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#include "InputManager.h"

class Player
{
private:
	InputManager im;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Sprite head;

	float rotation;

	sf::Vector2f position;
	sf::Vector2f velocity;
	float xScale = 0.3f;
	float yScale = 0.3f;
	float speed = 0.03f;

	bool vert = false;
	bool run = false;
	bool smell = false;
	bool left = false, right = false, up = false, down = false;

public:
	Player();
	Player(float x, float y);

	void Update(sf::Event event);
	void Draw(sf::RenderWindow &win);

	void MoveK(int dir);
	void isRunning(bool r);

	sf::Vector2f GetPosition();
	sf::Sprite GetSprite();

	Player::~Player() {};
};

#endif