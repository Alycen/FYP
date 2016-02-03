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
	SceneManager() {
		currentScene = new SplashScene();
	}
public:
	~SceneManager() {
		delete instance;
		instanceFlag = false;
	};

	static SceneManager* GetInstance();

	static bool instanceFlag;
	static SceneManager* instance;
	void set(string scene);
	BaseScene get();

	//void Update(float deltaTime);
	void Update();
	void Draw(sf::RenderWindow &win);
};

#endif