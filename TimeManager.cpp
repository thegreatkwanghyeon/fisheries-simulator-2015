#include "TimeManager.h"
#include "Global.h"

TimeManager::TimeManager() : timeRemaining(60.0f){
	font.loadFromFile("font/numbers.ttf");
	time.setFont(font);
	time.setCharacterSize(24);
	time.setPosition(0,30);
	time.setColor(Color(255,255,255));
}

TimeManager::~TimeManager(){
}

void TimeManager::update(){

	timeRemaining -= clock.getElapsedTime().asSeconds()*timeRatio;
	time.setString("Time : " + to_string((int)ceil(timeRemaining)));


	clock.restart();
}

void TimeManager::draw(RenderWindow &window){
	window.draw(time);
}

void TimeManager::setTime(float time){
	timeRemaining = time;
}

float TimeManager::getTime(){
	return timeRemaining;
}