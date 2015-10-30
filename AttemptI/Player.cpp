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

}

void Player::Draw(sf::RenderWindow &win) 
{
	win.draw(sprite);
}

void Player::Move() 
{
	// In combat :
	// if ( mouse.y is less than player.y ) 
	//     player.sprite is facing North
	// etc ...

	// if ( player.sprite is facing North && player is not moving North ) 
	//     Slow players movement speed
	// etc ...
}