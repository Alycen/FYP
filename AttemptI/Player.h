#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include "SFML\Audio.hpp"
#include <iostream> 
#include <math.h>
#include "InputManager.h"
#include "Smell.h"

#define DistanceToNeck 12.5

class Player
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Texture texture_Head;
	sf::Sprite head;
	float rotation;

	sf::Vector2f position;
	sf::Vector2f direction;
	float xScale = 0.3f;
	float yScale = 0.3f;
	float speed;
	bool run = false;

	bool smell = false;
	sf::CircleShape smellCircle;
	float radius;

	sf::SoundBuffer barkbuffer;
	sf::Sound barksound;
public:
	Player();
	Player(float x, float y);

	void Update();
	void Draw(sf::RenderWindow &win);

	void isRunning(bool r);
	void Smell();
	sf::CircleShape GetCircle();
	sf::Vector2f GetPosition();
	void SetPosition(float x, float y);
	sf::Sprite GetSprite();

	Player::~Player() {};
};

#endif