#include "Particle.h"

Particle::Particle() {
	texture.loadFromFile("particle.png");
	texture.setSmooth(true);

	sprite.setTexture(texture);

}

Particle::Particle(float x, float y) {
	texture.loadFromFile("particle.png");
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