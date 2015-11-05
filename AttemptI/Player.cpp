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
		position.y -= 1;
	else if (down)
		position.y += 1;
	if (left)
		position.x -= 2;
	else if (right) 
		position.x += 2;
}

void Player::Draw(sf::RenderWindow &win) 
{
	win.draw(sprite);
}

void Player::Move(int dir) 
{
	int UP = 1, LEFT = 2, DOWN = 3, RIGHT = 4;
	if (dir == UP)
		up = true; //position.y -= 2;
	else if (dir == DOWN)
		down = true; //position.y += 2;
	if (dir == LEFT)
		left = true; //position.x -= 3;
	else if (dir == RIGHT)
		right = true; //position.x += 3;

	else if (dir == 0) {
		up = false;
		down = false;
		left = false;
		right = false;
	}
		
	// May have to change how this method works / InputManager checked outside of the player and then have a command sent to this method;
	// In combat :
	// if ( mouse.y is less than player.y ) 
	//     player.sprite is facing North
	// etc ...

	// if ( player.sprite is facing North && player is not moving North ) 
	//     Slow players movement speed
	// etc ...
}