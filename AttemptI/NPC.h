#ifndef NPC_H
#define NPC_H

using namespace std;

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#include "ResourceManager.h"

class NPC
{
private:
	ResourceManager rm;

	int timer = rand() % 100 + 1;

	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2f position;
	sf::Vector2f velocity;
	float xScale = 0.3f;
	float yScale = 0.3f;

public:
	NPC();
	NPC(float x, float y);
	
	void Update();
	void Draw(sf::RenderWindow &win);
	void Move();
	
	NPC::~NPC() {};
};
#endif