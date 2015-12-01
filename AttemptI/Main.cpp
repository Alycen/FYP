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
#include "SceneManager.h"
//#include "GameScene.h"
//#include "SplashScene.h"

// Need to add Box2D

int main()
{
	srand(time(NULL));

	InputManager im = InputManager();
	static SceneManager sm = sceneManagerInstance;
	//GameScene game = GameScene();
	//SplashScene splash = SplashScene();

	sf::RenderWindow window(sf::VideoMode(1400, 900, 32), "Project Mk 1");
	
	sf::View camera; 
	camera.setSize(sf::Vector2f(1200, 800));
	int screenW = int(window.getSize().x), screenH = int(window.getSize().y);

	//Player player = Player(900.0f, 200.0f);
	//NPC npc_01 = NPC(600.f, 500.0f);

	while (window.isOpen())
	{ 
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
				window.close();
			
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				window.close();

			/*if (im.CheckInput(Event, sf::Keyboard::W)) {
				if (Event.type == sf::Event::KeyPressed)
					game.PlayerControl(1);
				else if (Event.type == sf::Event::KeyReleased)
					game.PlayerControl(5);
			}
			if (im.CheckInput(Event, sf::Keyboard::A)) {
				if (Event.type == sf::Event::KeyPressed)
					game.PlayerControl(2);
				else if (Event.type == sf::Event::KeyReleased)
					game.PlayerControl(10);
			}
			if (im.CheckInput(Event, sf::Keyboard::S)) {
				if (Event.type == sf::Event::KeyPressed)
					game.PlayerControl(3);
				else if (Event.type == sf::Event::KeyReleased)
					game.PlayerControl(15);
			}
			if (im.CheckInput(Event, sf::Keyboard::D)) {
				if (Event.type == sf::Event::KeyPressed)
					game.PlayerControl(4);
				else if (Event.type == sf::Event::KeyReleased)
					game.PlayerControl(20);
			}
			if (im.CheckInput(Event, sf::Keyboard::LShift) || im.CheckInput(Event, sf::Keyboard::RShift)) {
				if (Event.type == sf::Event::KeyPressed)
					game.player->isRunning(true);
				else if (Event.type == sf::Event::KeyReleased)
					game.player->isRunning(false);
			}*/

		}
		//camera.setCenter(player.GetPosition());
		
		//window.setView(camera);

		//player.Update();
		//npc_01.Update();
		//game.Update();
		sm.Update();
		window.clear();
		sm.Draw(window);
		//game.Draw(window);
		//npc_01.Draw(window);
		//player.Draw(window);

		window.display();
	}
	return EXIT_SUCCESS;
}