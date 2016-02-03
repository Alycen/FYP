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
#include "Particle.h"

//TinyXML
//PugiXML

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1400, 900, 32), "Project Mk 3");	

	/* Load a font and setup some texty-type stuff */
	sf::Font font;
	if (!font.loadFromFile("Assets/fonts/VINERITC.TTF"))
		return 1;
	sf::Text text("", font, 12);
	text.setPosition(
		static_cast<float>(window.getSize().x) * 0.01f,
		static_cast<float>(window.getSize().y) * 0.01f);

	/* Create the particle system and give it some fuel */
	ParticleSystem particleSystem(window.getSize());
	particleSystem.fuel(1000);

	/* Let's make a clock and junk for timing stuff! */
	sf::Clock timer;
	const sf::Uint32 UPDATE_STEP = 20;
	const sf::Uint32 MAX_UPDATE_SKIP = 5;
	sf::Uint32 nextUpdate = timer.getElapsedTime().asMilliseconds();


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



			switch (Event.type)
			{
			case(sf::Event::Closed) :
			{
				window.close();
				break;
			}
			case(sf::Event::KeyPressed) :
			{
				if (Event.key.code == sf::Keyboard::Escape)
					window.close();
				if (Event.key.code == sf::Keyboard::Space)
					particleSystem.setDissolve();
				if (Event.key.code == sf::Keyboard::A)
				{
					if (particleSystem.getDissolutionRate() > 0)
						particleSystem.setDissolutionRate(
							particleSystem.getDissolutionRate() - 1);
				}
				if (Event.key.code == sf::Keyboard::S)
					particleSystem.setDissolutionRate(
						particleSystem.getDissolutionRate() + 1);
				if (Event.key.code == sf::Keyboard::W)
					particleSystem.setParticleSpeed(
						particleSystem.getParticleSpeed()
						+ particleSystem.getParticleSpeed() * 0.1);
				if (Event.key.code == sf::Keyboard::Q
					&& particleSystem.getParticleSpeed() > 0)
					particleSystem.setParticleSpeed(
						particleSystem.getParticleSpeed()
						- particleSystem.getParticleSpeed() * 0.1);
				if (Event.key.code == sf::Keyboard::E)
					particleSystem.setDistribution();
				break;
			}
			default:
				break;
			}
		}
		

		if (time == 0) {
			SceneManager::GetInstance()->set("MAINMENU");
		}
		if (time == -20000) {
			SceneManager::GetInstance()->set("GAME");
		}

		time--;
		SceneManager::GetInstance()->Update();

		InputManager::GetInstance()->UpdateState();
		window.clear();
		SceneManager::GetInstance()->Draw(window);


		window.clear(sf::Color::Black);
		window.draw(text);
		window.draw(particleSystem);
		window.display();
	}


	return EXIT_SUCCESS;
}