#include "NPC.h"

NPC::NPC() { }

NPC::NPC(float x, float y) {
	position.x = x;
	position.y = y;

	texture.loadFromFile("Assets/npc1.png");
	texture.setSmooth(true);

	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setRotation(0);
	sprite.setPosition(position);
	sprite.setScale(xScale, yScale);

	texture_Head.loadFromFile("Assets/headNPC1.png");
	texture_Head.setSmooth(true);

	head.setTexture(texture_Head);
	head.setOrigin(21.0f, 37.0f);
	head.setPosition(position.x, position.y - DistanceToNeck);
	head.setScale(xScale, yScale);
}

void NPC::Update() {
	sprite.setPosition(position);
	Move();
}

void NPC::Draw(sf::RenderWindow &win) {
	win.draw(sprite);
	win.draw(head);
}

void NPC::Move() {
	if (timer == 0) {
		timer = 5000;
		dir = rand() % 7 + 1;
	}

	if (dir == 2 && position.x < 790) {
		direction.x++;
		//sprite.setPosition(position.x += 0.02f, position.y);
	}
	else if (dir == 1 && position.x > 10) {
		direction.x--;
		//sprite.setPosition(position.x -= 0.02f, position.y);
	}
	else if (dir == 4 && position.y < 590) {
		direction.y++;
	}
	else if (dir == 3 && position.y > 10) {
		direction.y--;
	}
	else {
		direction.x = 0;
		direction.y = 0;
		//sprite.setPosition(position.x, position.y);
	}

	float length = sqrt((direction.x * direction.x) + (direction.y * direction.y));

	if (length > 0) {
		sf::Vector2f normalised = direction / length;
		position += normalised * speed;
		sprite.setRotation(atan2(normalised.y, normalised.x) * 180 / (22.0f / 7.0f) + 90.0f);

		sprite.setPosition(position);
		head.setPosition(position + (normalised * (float)DistanceToNeck));
		head.setRotation(atan2(normalised.y, normalised.x) * 180 / (22.0f / 7.0f) + 90.0f);
	}

	timer--;
}