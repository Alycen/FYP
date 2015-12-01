#include "SceneManager.h"

SceneManager sceneManagerInstance;

SceneManager::SceneManager() {
	currentScene = new SplashScene();
}

void SceneManager::set(BaseScene* scene) {
	currentScene = scene;
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