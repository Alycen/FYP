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

	sf::RenderWindow window(sf::VideoMode(1400, 900, 32), "Project Mk 3");	

	int time = 20000;

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
			SceneManager::GetInstance()->set("MAINMENU");
		}
		time--;
		SceneManager::GetInstance()->Update();
		//sm.Update();

		InputManager::GetInstance()->UpdateState();
		window.clear();
		SceneManager::GetInstance()->Draw(window);
		//sm.Draw(window);

		window.display();
	}
	return EXIT_SUCCESS;
}