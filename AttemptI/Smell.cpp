#include "Smell.h"

Smell::Smell() {
	range = 25.0f;
}

Smell::Smell(float x, float y) {

}

void Smell::Update() {

}

void Smell::Activate() {

}

void Smell::Draw(sf::RenderWindow &win) {

}

Smell::~Smell() {

}

void Smell::SetRange(float r) {
	range = r;
}

float Smell::GetRange() {
	return range;
}