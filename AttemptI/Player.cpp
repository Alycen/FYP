#include "Player.h"

Player::Player() { }

Player::Player(float x, float y) {
	im = InputManager();
	position.x = x;
	position.y = y;

	texture.loadFromFile("Player.png");
	texture.setSmooth(true);

	sprite.setTexture(texture);
	sprite.setPosition(position);
	sprite.setScale(xScale, yScale);
}

void Player::Update(sf::Event event) {
	if (im.CheckInput(event, sf::Keyboard::W)) {
		if (event.type == sf::Event::KeyPressed)
			MoveK(1);
		else if (event.type == sf::Event::KeyReleased)
			MoveK(5);
	}
	if (im.CheckInput(event, sf::Keyboard::A)) {
		if (event.type == sf::Event::KeyPressed)
			MoveK(2);
		else if (event.type == sf::Event::KeyReleased)
			MoveK(10);
	}
	if (im.CheckInput(event, sf::Keyboard::S)) {
		if (event.type == sf::Event::KeyPressed)
			MoveK(3);
		else if (event.type == sf::Event::KeyReleased)
			MoveK(15);
	}
	if (im.CheckInput(event, sf::Keyboard::D)) {
		if (event.type == sf::Event::KeyPressed)
			MoveK(4);
		else if (event.type == sf::Event::KeyReleased)
			MoveK(20);
	}
	if (im.CheckInput(event, sf::Keyboard::LShift) || im.CheckInput(event, sf::Keyboard::RShift)) {
		if (event.type == sf::Event::KeyPressed)
			isRunning(true);
		else if (event.type == sf::Event::KeyReleased)
			isRunning(false);
	}

	if (im.CheckInput(event, sf::Keyboard::LAlt) || im.CheckInput(event, sf::Keyboard::RAlt)) {
		smell = true;
	}

	if (run) {
		if (vert) {
			vSpeed = 0.02;
			hSpeed = 0.02f;
		}
		else {
			vSpeed = 0.04f;
			hSpeed = 0.03f;
		}
	}
	else {
		if (vert) {
			vSpeed = 0.01f;
			hSpeed = 0.01f;
		}
		else {
			vSpeed = 0.02f;
			hSpeed = 0.02f;
		}
	}

	if (smell) {

	}

	sprite.setPosition(position);
	if (up)
		position.y -= hSpeed;
	else if (down)
		position.y += hSpeed;
	if (left)
		position.x -= vSpeed;
	else if (right) 
		position.x += vSpeed;
}

void Player::Draw(sf::RenderWindow &win) {
	win.draw(sprite);
}

void Player::MoveK(int dir) {
	int UP = 1, LEFT = 2, DOWN = 3, RIGHT = 4;
	if (dir == UP) {
		up = true;
		vert = true;
	}
	else if (dir == DOWN) {
		down = true;
		vert = true;
	}
	if (dir == LEFT) {
		left = true;
	}
	else if (dir == RIGHT) {
		right = true;
	}

	if (dir == UP * 5) {
		up = false;
		vert = false;
	}
	if (dir == LEFT * 5) {
		left = false;
	}
	if (dir == DOWN * 5) {
		down = false;
		vert = false;
	}
	if (dir == RIGHT * 5)
		right = false;
}

void Player::isRunning(bool r) {
	run = r;
}

sf::Vector2f Player::GetPosition() {
	return position;
}

sf::Sprite Player::GetSprite() {
	return sprite;
}