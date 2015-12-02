#pragma once
#ifndef BASESCENE_H
#define BASESCENE_H
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 

class BaseScene 
{
protected:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	BaseScene::BaseScene() {} 
	BaseScene::~BaseScene() {}
	virtual void BaseScene::Update(sf::Event event) {
	
	}
	virtual void BaseScene::Draw(sf::RenderWindow &win) {
		win.draw(sprite);
	}
};

#endif