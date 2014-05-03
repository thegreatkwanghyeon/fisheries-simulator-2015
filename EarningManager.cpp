#include "EarningManager.h"

EarningManager::EarningManager() : currentEarning(0), visualEarning(0){
	font.loadFromFile("font/numbers.ttf");
	earning.setFont(font);
	earning.setColor(Color(251,184,41));
	earning.setCharacterSize(24);
}

EarningManager::~EarningManager(){
}

void EarningManager::update(){
	if(visualEarning < currentEarning)
		visualEarning++;

	earning.setString("Earning : " + to_string(visualEarning));

}

void EarningManager::draw(RenderWindow &window){
	window.draw(earning);
}

void EarningManager::increaseEarning(unsigned int value){
	currentEarning += value;
}

unsigned int EarningManager::getEarning(){
	return currentEarning;
}