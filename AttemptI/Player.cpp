#include "Player.h"

Player::Player() { }

Player::Player(float x, float y) {
	im = InputManager();
	position.x = x;
	position.y = y;

	texture.loadFromFile("Player.png");
	texture.setSmooth(true);

	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height);
	sprite.setRotation(0);
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
			speed = 0.03f;
		}
		else {
			speed = 0.04f;
		}
	}
	else {
		if (vert) {
			speed = 0.02f;
		}
		else {
			speed = 0.03f;
		}
	}

	if (smell) {

	}

	sprite.setPosition(position);
	if (up)
		position.y -= speed;
	else if (down)
		position.y += speed;
	if (left)
		position.x -= speed;
	else if (right) 
		position.x += speed;
}

void Player::Draw(sf::RenderWindow &win) {
	win.draw(sprite);
}

void Player::MoveK(int dir) {
	int UP = 1, LEFT = 2, DOWN = 3, RIGHT = 4;
	if (dir == UP) {
		up = true;
		down = false;
		vert = true;
		if (right)
			sprite.setRotation(45);
		else if (left)
			sprite.setRotation(315);
		else if (!right || !left)
			sprite.setRotation(0);
	}
	else if (dir == DOWN) {
		down = true;
		up = false;
		vert = true;
		if (right)
			sprite.setRotation(135);
		else if (left)
			sprite.setRotation(225);
		else if (!left || ! right)
			sprite.setRotation(180);
	}
	if (dir == LEFT) {
		left = true;
		right = false;
		if (down)
			sprite.setRotation(225);
		else if (up)
			sprite.setRotation(315);
		else if (!down || !up)
			sprite.setRotation(270);
	}
	else if (dir == RIGHT) {
		right = true;
		left = false; 
		if (down)
			sprite.setRotation(135);
		else if (up)
			sprite.setRotation(45);
		else if (!down || !up)
			sprite.setRotation(90);
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