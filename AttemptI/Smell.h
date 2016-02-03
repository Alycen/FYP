#ifndef _SMELL_
#define _SMELL_

#include "SFML\Graphics.hpp"
#include <list>

class Smell {
private:
	sf::CircleShape bounds;
	sf::Vector2f velocity;
	sf::Vector2f position;
	float range;
public:
	Smell();
	Smell(float x, float y);
	~Smell();

	void Activate();
	void Update();
	void Draw(sf::RenderWindow &win);

	void SetRange(float r);
	float GetRange();
};

#endif