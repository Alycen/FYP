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
	//Move();
}

void NPC::Draw(sf::RenderWindow &win)
{
	win.draw(sprite);
}

void NPC::Move() 
{
	int dir = rand() % 2 + 1;
	for (int i = 0; i < timer; i ++) 
	{
		cout << dir << endl;
		if (dir == 1)
			position.x += 0.001f;
		else if (dir == 2)
			position.x -= 0.001f;
		else
			position.x = position.x;
	
		if (i == timer)
			timer = rand() % 100000 + 1;
	}
}