#ifndef _EMITTER_
#define _EMITTER_

#include "SFML\Graphics.hpp"
#include "Particle.h"
#include <list>
using namespace std;

class Emitter {
private:
	sf::Vector2f position;
	list<Particle*> particles;
public:
	Emitter();
	~Emitter();

	void Update();
	void Draw(sf::RenderWindow &win);
};

#endif