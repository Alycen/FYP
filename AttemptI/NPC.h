#ifndef NPC_H
#define NPC_H

using namespace std;

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#include "Particle.h"

#define DistanceToNeck 12.5

class NPC
{
private:
	int timer = 5000;
	int dir = rand() % 7 + 1;

	sf::Texture texture;
	sf::Sprite sprite;
	sf::Texture texture_Head;
	sf::Sprite head;

	sf::Vector2f position;
	sf::Vector2f direction;
	float xScale = 0.3f;
	float yScale = 0.3f;
	float speed = 0.03f;

public:
	NPC();
	NPC(float x, float y);
	
	void Update();
	void Draw(sf::RenderWindow &win);
	void Move();
	
	NPC::~NPC() {};
};
#endif