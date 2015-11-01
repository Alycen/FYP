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
	
public:
	SceneManager() {}
	enum SceneType {
		SCENE_SPLASH,
		SCENE_MAINMENU,
		SCENE_GAME,
		SCENE_LOADING,
	};
	static SceneManager &Instance() {
		static SceneManager sm; 
		return sm;
	}
};

extern SceneManager sceneManagerInstance;

#endif