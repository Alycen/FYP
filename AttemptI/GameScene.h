#pragma once
#ifndef GAMESCENE_H
#define GAMESCENE_H

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

#include "BaseScene.h"
#include "Player.h"
#include "NPC.h"

//#include "SFML\Graphics.hpp"

class GameScene : public BaseScene
{
private:
	NPC npc_01;
public:
	sf::RenderWindow *window;//(sf::VideoMode(1200, 800, 32), "Project Mk 1");
	Player player;
	GameScene();
	void PlayerControl(int dir);
	void Update();
	void Draw(sf::RenderWindow &win);

	GameScene::~GameScene() { };
};

#endif