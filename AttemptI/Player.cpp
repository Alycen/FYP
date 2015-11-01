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
}

void Player::Draw(sf::RenderWindow &win) 
{
	win.draw(sprite);
}

void Player::Move(int dir) 
{
	int UP = 1, LEFT = 2, DOWN = 3, RIGHT = 4;
	if (dir == UP) 
		position.y -= 2;
	else if (dir == DOWN)
		position.y += 2;
	if (dir == LEFT)
		position.x -= 3;
	else if (dir == RIGHT)
		position.x += 3;
		
	// May have to change how this method works / InputManager checked outside of the player and then have a command sent to this method;
	// In combat :
	// if ( mouse.y is less than player.y ) 
	//     player.sprite is facing North
	// etc ...

	// if ( player.sprite is facing North && player is not moving North ) 
	//     Slow players movement speed
	// etc ...
}

void Player::Move(sf::Vector2i pos) 
{
	position.x = float(pos.x);
	position.y = float(pos.y);
}