#pragma once
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 

class InputManager
{
private:

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

	//sf::Vector2i InputManager::CheckMouse(sf::Mouse::Button mouse, sf::Mouse pos) {
	//	if (mouse == sf::Mouse::Button::Left)
	//		return pos.getPosition();
	//}

	InputManager::~InputManager() { }
};

#endif