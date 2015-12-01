#pragma once
#ifndef SPLASHSCENE_H
#define SPLASHSCENE_H

#include "BaseScene.h"

class SplashScene : public BaseScene
{
private:
	float ttl;
public:
	SplashScene::SplashScene() {
		texture.loadFromFile("Splash.png");
		texture.setSmooth(true);
		
		sprite.setTexture(texture);
		sprite.setPosition(texture.getSize().x / 3, texture.getSize().y / 4);
	}
};

#endif