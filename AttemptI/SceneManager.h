#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "BaseScene.h"
#include "SplashScene.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include "LoadingScene.h"

class SceneManager
{
private:
	BaseScene* currentScene;
public:
	SceneManager();
	~SceneManager();

	static SceneManager &Instance() {
		static SceneManager sm; 
		return sm;
	}

	void set(string scene);
	BaseScene get();

	//void Update(float deltaTime);
	void Update(sf::Event);
	void Draw(sf::RenderWindow &win);
};

extern SceneManager sceneManagerInstance;

#endif