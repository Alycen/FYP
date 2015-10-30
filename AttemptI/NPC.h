#pragma once
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

	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2f position;
	sf::Vector2f velocity;
	float xScale;
	float yScale;

public:
	NPC();
	NPC(float x, float y);
	
	void Update();
	void Draw(sf::RenderWindow &win);
	void Move();
	
	NPC::~NPC();
};
#endif