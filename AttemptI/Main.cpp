#include "stdafx.h" 
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#define _USE_MATH_DEFINES
#include <math.h>
//#include "Player.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "SceneManager.h"

int main()
{
	InputManager im = new InputManager();
	ResourceManager rm = new ResourceManager();
	static SceneManager sm = sceneManagerInstance;

	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Project Mk 1");
	//Player player = Player(200.0f, 200.0f);

	while (window.isOpen())
	{ 
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
				window.close();
			
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				window.close();
		}
		window.clear();
		//player.Draw(window);
		window.display();
	}
	return EXIT_SUCCESS;
}