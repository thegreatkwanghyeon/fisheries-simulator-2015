#include "TimeManager.h"

TimeManager::TimeManager() : timeRemaining(60.0f){

}

TimeManager::~TimeManager(){
}

void TimeManager::update(){

	timeRemaining -= clock.getElapsedTime().asSeconds();

	clock.restart();
}

void TimeManager::draw(RenderWindow &window){
}

void TimeManager::setTime(float time){
	timeRemaining = time;
}

float TimeManager::getTime(){
	return timeRemaining;
}