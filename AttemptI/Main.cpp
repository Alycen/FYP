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
#include "InputManager.h"
#include "ResourceManager.h"
#include "SceneManager.h"

int main()
{
	srand(time(NULL));

	InputManager im = InputManager();
	ResourceManager rm = ResourceManager();
	static SceneManager sm = sceneManagerInstance;

	sf::RenderWindow window(sf::VideoMode(1200, 800, 32), "Project Mk 1");
	sf::View camera; //(sf::FloatRect(200, 800, 150, 550));
	camera.setCenter(sf::Vector2f(600, 400));
	camera.setSize(sf::Vector2f(1000, 600));
	int screenW = int(window.getSize().x), screenH = int(window.getSize().y);

	Player player = Player(900.0f, 200.0f);
	NPC npc_01 = NPC(600.f, 500.0f);

	while (window.isOpen())
	{ 
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
				window.close();
			
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				window.close();

			if (im.CheckInput(Event, sf::Keyboard::W) && Event.type == sf::Event::KeyPressed) 
				player.Move(1);
			if (im.CheckInput(Event, sf::Keyboard::W) && Event.type == sf::Event::KeyReleased) 
				player.Move(5);

			if (im.CheckInput(Event, sf::Keyboard::A) && Event.type == sf::Event::KeyPressed) 
				player.Move(2);
			if (im.CheckInput(Event, sf::Keyboard::A) && Event.type == sf::Event::KeyReleased) 
				player.Move(10);

			if (im.CheckInput(Event, sf::Keyboard::S) && Event.type == sf::Event::KeyPressed) 
				player.Move(3);
			if (im.CheckInput(Event, sf::Keyboard::S) && Event.type == sf::Event::KeyReleased) 
				player.Move(15);

			if (im.CheckInput(Event, sf::Keyboard::D) && Event.type == sf::Event::KeyPressed) 
				player.Move(4);
			if (im.CheckInput(Event, sf::Keyboard::D) && Event.type == sf::Event::KeyReleased) 
				player.Move(20);

			if ((im.CheckInput(Event, sf::Keyboard::LShift) || im.CheckInput(Event, sf::Keyboard::RShift)) && Event.type == sf::Event::KeyPressed)
				player.isRunning(true);
			if ((im.CheckInput(Event, sf::Keyboard::LShift) || im.CheckInput(Event, sf::Keyboard::RShift)) && Event.type == sf::Event::KeyReleased)
				player.isRunning(false);
		}

		player.Update();
		npc_01.Update();

		window.clear();
		npc_01.Draw(window);
		player.Draw(window);
		window.display();
	}
	return EXIT_SUCCESS;
}