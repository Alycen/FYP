#ifndef _PARTICLE_
#define _PARTICLE_

#include "SFML\Graphics.hpp"

class Particle {
private:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Particle();
	Particle(float x, float y);
	~Particle();

	void Update();
	void Draw(sf::RenderWindow &win);
};

#endif