#ifndef _PARTICLE_
#define _PARTICLE_

#include "SFML\Graphics.hpp"

class Particle {
private:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Color colour;
	bool visible;
public:
	Particle();
	Particle(float x, float y);
	~Particle();

	void Update();
	void Draw(sf::RenderWindow &win);
	void toPlayer(sf::Vector2f &target);
	void setColour(sf::Color col);
	void trail(sf::Vector2f pos);
	void setVisible(bool vis);
};

#endif