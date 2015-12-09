#include "SceneManager.h"

SceneManager sceneManagerInstance;

SceneManager::SceneManager() {
	currentScene = new SplashScene();
}

void SceneManager::set(string scene) {
	if (scene == "SPLASH") {
		delete currentScene;
		//currentScene->~BaseScene();
		currentScene = new SplashScene();
	}
	if (scene == "MAINMENU") {
		delete currentScene;
		currentScene = new MainMenuScene();
	}
	if (scene == "GAME") {
		delete currentScene;
		currentScene = new GameScene();
	}
	//if (scene == "LOADING") {
	//	currentScene = new LoadingScene();
	//}
}

BaseScene SceneManager::get() {
	return *currentScene;
}

//void SceneManager::Update(float deltaTime) {
void SceneManager::Update() {
	currentScene->Update();
}

void SceneManager::Draw(sf::RenderWindow &win) {
	currentScene->Draw(win);
}


SceneManager::~SceneManager() {
	currentScene->~BaseScene();
}