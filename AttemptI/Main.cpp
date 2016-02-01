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
#include "Camera.h"
//#include "GameScene.h"
//#include "SplashScene.h"

//TinyXML
//PugiXML


int main()
{
	srand(time(NULL));

	static SceneManager sm = sceneManagerInstance;
	//GameScene game = GameScene();
	//SplashScene splash = SplashScene();

	sf::RenderWindow window(sf::VideoMode(1400, 900, 32), "Project Mk 3");	
	//int screenW = int(window.getSize().x), screenH = int(window.getSize().y);
	int time = 15000;

	while (window.isOpen())
	{ 
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			InputManager::GetInstance()->UpdatePolledEvents(Event);
			if (Event.type == sf::Event::Closed)
				window.close();
			
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				window.close();
		}
		if (time == 0) {
			sm.set("GAME");

		}
		time--;
		//camera.setCenter(player->GetPosition());
		
		//window.setView(Camera::GetInstance()->getView());

		sm.Update();

		InputManager::GetInstance()->UpdateState();
		window.clear();
		sm.Draw(window);

		window.display();
	}
	return EXIT_SUCCESS;
}