#include "Player.h"

Player::Player() { }

//https://github.com/SFML/SFML/wiki/Tutorial:-Manage-different-Screens

bool Player::instanceFlag = false;
Player* Player::instance = NULL;

Player* Player::GetInstance() {
	if (!instanceFlag) {
		instance = new Player;
		instanceFlag = true;
		return instance;
	}
	else {
		return instance;
	}
}

Player::Player(float x, float y) {
	//smellSence = Smell();
	position.x = x;
	position.y = y;

	texture.loadFromFile("Assets/Player1.png");
	texture.setSmooth(true);

	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setRotation(0);
	sprite.setPosition(position);
	sprite.setScale(xScale, yScale);

	texture_Head.loadFromFile("Assets/head1.png");
	texture_Head.setSmooth(true);

	head.setTexture(texture_Head);
	head.setOrigin(21.0f, 37.0f);
	head.setPosition(position.x, position.y - DistanceToNeck);
	head.setScale(xScale, yScale);

	barkbuffer.loadFromFile("Assets/Sounds/14_DOGGI.wav");
	barksound.setBuffer(barkbuffer);

	radius = 500.0f;
}

void Player::Update() {
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
	
	// Run
	if (InputManager::GetInstance()->IsKeyDown(sf::Keyboard::LShift)) {
		run = true;
	}
	else if (InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::LShift)) {
		run = false;
	}

	// Smell
	if (InputManager::GetInstance()->IsKeyDown(sf::Keyboard::LAlt) || InputManager::GetInstance()->IsKeyDown(sf::Keyboard::RAlt)) {
		Smell();
	}
	if ((InputManager::GetInstance()->IsKeyHeld(sf::Keyboard::LAlt) || InputManager::GetInstance()->IsKeyHeld(sf::Keyboard::RAlt)) && smellCircle.getRadius() < radius) {
		smell = true;
	}
	else if (InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::LAlt) || InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::RAlt) || smellCircle.getRadius() >= radius) {
	    smell = false;
	}

	if (run) {
		speed = 0.25;
	}
	else {
		speed = 0.115;
	}

	if (smell) {
	}

	//Normalise direction
	float length = sqrt((direction.x * direction.x) + (direction.y * direction.y));
	
	if(length > 0)	{
		sf::Vector2f normalised = direction / length;
		position += normalised * speed;
		sprite.setRotation(atan2(normalised.y, normalised.x) * 180 / (22.0f/7.0f) + 90.0f);

		sprite.setPosition(position);
		head.setPosition(position + (normalised * (float)DistanceToNeck));
		head.setRotation(atan2(normalised.y, normalised.x) * 180 / (22.0f / 7.0f) + 90.0f);
	}

	if (InputManager::GetInstance()->IsKeyDown(sf::Keyboard::E)) {
		barksound.play();
	}
	Camera::GetInstance()->setViewPosition(sf::Vector2f(position.x, position.y));
}

void Player::Smell() {
	//smellCircle.setOrigin(position);
	smellCircle.setPosition(position.x - (smellCircle.getRadius()), position.y - (smellCircle.getRadius()));
	smellCircle.setRadius(0.0f);
	smellCircle.setFillColor(sf::Color::Transparent);
	smellCircle.setOutlineColor(sf::Color::White);
	smellCircle.setOutlineThickness(3);
}

void Player::Draw(sf::RenderWindow &win) {
	win.draw(sprite);
	win.draw(head);
	if (smell)
		win.draw(smellCircle);
		if (smellCircle.getRadius() < radius) {
			smellCircle.setRadius(smellCircle.getRadius() + .15f);
			smellCircle.setPosition(position.x - (smellCircle.getRadius()), position.y - (smellCircle.getRadius()));
		}
		else if (smellCircle.getRadius() == radius) {
			smell = false;
		}
}

void Player::isRunning(bool r) {
	run = r;
}

sf::Vector2f Player::GetPosition() {
	return position;
}

void Player::SetPosition(float x, float y) {
	position = sf::Vector2f(x, y);
}

sf::Sprite Player::GetSprite() {
	return sprite;
}

sf::CircleShape Player::GetCircle() {
	return smellCircle;
}
