#include "NPC.h"

using namespace std;

NPC::NPC() { }

NPC::NPC(float x, float y)
{
	position.x = x;
	position.y = y;

	texture.loadFromFile("npc.png");
	texture.setSmooth(true);

	sprite.setTexture(texture);
	sprite.setPosition(position);
	sprite.setScale(xScale, yScale);
}

void NPC::Update()
{
	sprite.setPosition(position);
	Move();
}

void NPC::Draw(sf::RenderWindow &win)
{
	win.draw(sprite);
}

void NPC::Move() 
{
	
}