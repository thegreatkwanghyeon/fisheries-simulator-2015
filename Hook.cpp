/*
 *  Date: 2014-04-12
 *	Version: 1.0
 */

#include "Hook.h"



Hook::Hook() : currentDirection(0), movementConstant(0.05f){
	texture.loadFromFile("img/hook.png");
	sprite.setTexture(texture);
	sprite.setPosition(300,300);
}

Hook::~Hook(){
	
}

void Hook::update(){
	
	sprite.setRotation((cos(currentDirection)+sin(currentDirection))*60+90);
	currentDirection += movementConstant;
}

void Hook::draw(RenderWindow &window){
	window.draw(sprite);

}