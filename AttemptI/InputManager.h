#pragma once
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 

class InputManager
{
private:
	enum dir {
		UP,
		DOWN,
		LEFT,
		RIGHT,
	};
public:
	InputManager::InputManager() { }

	bool InputManager::CheckInput(sf::Event event, sf::Keyboard::Key key) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == key) 
				return true;
			else
				return false;
		}
	}

	InputManager::~InputManager() { }
};

#endif