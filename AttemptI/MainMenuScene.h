#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include "BaseScene.h"
#include "InputManager.h"
#include "SceneManager.h"
#include <iostream>

using namespace std;

#define NUM_OF_ELEMENTS 3

class MainMenuScene : public BaseScene 
{
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[NUM_OF_ELEMENTS];
public:
	MainMenuScene::MainMenuScene() {
		if (!font.loadFromFile("Assets/fonts/VINERITC.TTF")) {
			//handle error
		}
		menu[0].setFont(font);
		menu[0].setColor(sf::Color::Cyan);
		menu[0].setString("Play");
		menu[0].setPosition(sf::Vector2f(100 / 2, 400 / (NUM_OF_ELEMENTS + 1) * 1));

		menu[1].setFont(font);
		menu[1].setColor(sf::Color::White);
		menu[1].setString("Settings");
		menu[1].setPosition(sf::Vector2f(100 / 2, 400 / (NUM_OF_ELEMENTS + 1) * 2));

		menu[2].setFont(font);
		menu[2].setColor(sf::Color::White);
		menu[2].setString("Exit");
		menu[2].setPosition(sf::Vector2f(100 / 2, 400 / (NUM_OF_ELEMENTS + 1) * 3));

		selectedItemIndex = 0;
	}
	MainMenuScene::~MainMenuScene() { }

	void MainMenuScene::Update() {
		if (InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::W) || InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::Up)) {

			MoveUp();
		}
		else if (InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::S) || InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::Down)) {
			MoveDown();
		}

		if (InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::Return) || InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::Space)) {
			switch (GetPressedItem())
			{
			case 0:
				cout << "PLAY PRESSED" << endl;
				//SceneManager::GetInstance()->set("GAME");
				break;
			case 1:
				cout << "SETTINGS PRESSED" << endl;
				//SceneManager::GetInstance()->set("MAINMENU");
				break;
			case 2:
				cout << "EXIT PRESSED" << endl;
				//SceneManager::GetInstance()->set("MAINMENU");
				break;
			}
		}
	}

	void MainMenuScene::Draw(sf::RenderWindow &win) {
		for (int i = 0; i < NUM_OF_ELEMENTS; i++ ) {
			win.draw(menu[i]);
		}
	}
	void MainMenuScene::MoveUp() {
		if (selectedItemIndex - 1 >= 0) {
			menu[selectedItemIndex].setColor(sf::Color::White);
			selectedItemIndex--;
			menu[selectedItemIndex].setColor(sf::Color::Cyan);
		}
	}
	void MainMenuScene::MoveDown() {
		if (selectedItemIndex + 1 < NUM_OF_ELEMENTS) {
			menu[selectedItemIndex].setColor(sf::Color::White);
			selectedItemIndex++;
			menu[selectedItemIndex].setColor(sf::Color::Cyan);
		}
	}
	int MainMenuScene::GetPressedItem() { return selectedItemIndex; }
};

#endif