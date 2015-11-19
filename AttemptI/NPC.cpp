#include "NPC.h"

NPC::NPC() { }

NPC::NPC(float x, float y) {
	position.x = x;
	position.y = y;

	texture.loadFromFile("npc.png");
	texture.setSmooth(true);

	sprite.setTexture(texture);
	sprite.setPosition(position);
	sprite.setScale(xScale, yScale);
}

void NPC::Update() {
	sprite.setPosition(position);
	Move();
	cout << sprite.getPosition().x << endl;
}

void NPC::Draw(sf::RenderWindow &win) {
	win.draw(sprite);
}

void NPC::Move() {
	if (timer == 0) {
		timer = 10000;
		dir = rand() % 4 + 1;
	}
	if (dir == 2)
		sprite.setPosition(position.x += 0.02f, position.y);

	else if (dir == 1)
		sprite.setPosition(position.x -= 0.02f, position.y);

	else {
		sprite.setPosition(position.x, position.y);
	}

	timer--;
}