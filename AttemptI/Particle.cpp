#include "Particle.h"

Particle::Particle() {
	texture.loadFromFile("Assets/particle.png");
	texture.setSmooth(true);

	sprite.setTexture(texture);
	
}

Particle::Particle(float x, float y) {
	texture.loadFromFile("Assets/particle.png");
	texture.setSmooth(true);

	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}

Particle::~Particle() {

}

void Particle::Update() {

}

void Particle::Draw(sf::RenderWindow &win) {

}

void Particle::toPlayer(sf::Vector2f &target) {
	visible = true;
	if (position.x < target.x)
		position.x += 0.1f;
	else if (position.x > target.x)
		position.x -= 0.1f;
	if (position.y < target.y)
		position.y += 0.1f;
	else if (position.y > target.y) {
		position.y -= 0.1f;
	}
}

void Particle::setColour(sf::Color col) {
	colour = col;
}

void Particle::trail(sf::Vector2f pos) {
	visible - false;
	int ttl = 1000;
	position = pos;
}

void Particle::setVisible(bool vis) {
	visible = vis;
}