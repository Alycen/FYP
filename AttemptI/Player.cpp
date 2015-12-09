#include "Player.h"

Player::Player() { }

Player::Player(float x, float y) {
	//smellSence = Smell();
	position.x = x;
	position.y = y;

	texture.loadFromFile("Assets/Player.png");
	texture.setSmooth(true);

	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setRotation(0);
	sprite.setPosition(position);
	sprite.setScale(xScale, yScale);

	texture_Head.loadFromFile("Assets/head.png");
	texture_Head.setSmooth(true);

	head.setTexture(texture_Head);
	head.setOrigin(sprite.getOrigin().x - 7.5f, sprite.getOrigin().y + 30);
	head.setPosition(position);
	head.setScale(xScale, yScale);

}

void Player::Update() {
	//Y-Axis
	if (InputManager::GetInstance()->IsKeyDown(sf::Keyboard::W)) {
		direction.y--;
	}
	else if (InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::W)) {
		direction.y++;
	}
	if (InputManager::GetInstance()->IsKeyDown(sf::Keyboard::S)) {
		direction.y++;
	}
	else if (InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::S)) {
		direction.y--;
	}

	//X-Axis
	if (InputManager::GetInstance()->IsKeyDown(sf::Keyboard::A)) {
		direction.x--;
	}
	else if (InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::A)) {
		direction.x++;
	}
	if (InputManager::GetInstance()->IsKeyDown(sf::Keyboard::D)) {
		direction.x++;
	}
	else if (InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::D)) {
		direction.x--;
	}

	if (InputManager::GetInstance()->IsKeyDown(sf::Keyboard::LShift)) {
		run = true;
	}
	else if (InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::LShift)) {
		run = false;
	}
	//if (InputManager::GetInstance()->IsKeyDown(sf::Keyboard::LAlt) || InputManager::GetInstance()->IsKeyDown(sf::Keyboard::RAlt)) {
	//	smell = true;
	//}
	//else if (InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::LAlt) || InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::RAlt)) {
	//  smell = false;
	//}

	if (run) {
		speed = 0.04;
	}
	else {
		speed = 0.02;
	}

	if (smell) {
		//smellSence.Activate();
	}

	sprite.setPosition(position);
	head.setPosition(position);

	//Normalise direction
	float length = sqrt((direction.x * direction.x) + (direction.y * direction.y));
	
	if(length > 0)	{
		sf::Vector2f normalised = direction / length;
		position += normalised * speed;
		sprite.setRotation(atan2(normalised.y, normalised.x) * 180 / (22.0f/7.0f) - 90.0f);
	}
}

void Player::Draw(sf::RenderWindow &win) {
	win.draw(sprite);
	//win.draw(head);
	//if (smell)
	//	smellSence.Draw(win);
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