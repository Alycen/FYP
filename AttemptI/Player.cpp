#include "Player.h"

Player::Player() { }

Player::Player(float x, float y) 
{
	position.x = x;
	position.y = y;

	texture.loadFromFile("Player.png");
	texture.setSmooth(true);

	sprite.setTexture(texture);
	sprite.setPosition(position);
	sprite.setScale(xScale, yScale);
}

void Player::Update() 
{
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

void Player::Draw(sf::RenderWindow &win) 
{
	win.draw(sprite);
}

void Player::Move(int dir) 
{
	// Might have to control the run speed in this sections becuase player moves too fast if moving diagonally

	int UP = 1, LEFT = 2, DOWN = 3, RIGHT = 4;
	if (dir == UP)
		up = true;
	else if (dir == DOWN)
		down = true;
	if (dir == LEFT)
		left = true;
	else if (dir == RIGHT)
		right = true;

	if (dir == UP * 5)
		up = false;
	if (dir == LEFT * 5)
		left = false;
	if (dir == DOWN * 5)
		down = false;
	if (dir == RIGHT * 5)
		right = false;

	// May have to change how this method works / InputManager checked outside of the player and then have a command sent to this method;
	// In combat :
	// if ( mouse.y is less than player.y ) 
	//     player.sprite is facing North
	// etc ...

	// if ( player.sprite is facing North && player is not moving North ) 
	//     Slow players movement speed
	// etc ...
}

void Player::isRunning(bool r) 
{
	if (r) {
		vSpeed = 0.03f;
		hSpeed = 0.015f;
	}
	else {
		vSpeed = 0.01f;
		hSpeed = 0.005f;
	}
}