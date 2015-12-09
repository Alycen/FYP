#ifndef _SMELL_
#define _SMELL_

#include "SFML\Graphics.hpp"
#include "Emitter.h"
#include <list>

class Smell {
private:
	sf::CircleShape bounds;
	sf::Vector2f velocity;
	list<Emitter*> emitter;
public:
	Smell();
	~Smell();

	void Activate();
	void Update();
	void Draw(sf::RenderWindow &win);
};

#endif