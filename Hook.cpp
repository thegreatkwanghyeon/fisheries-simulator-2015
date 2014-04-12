/*
 *  Date: 2014-04-12
 *	Version: 1.0
 */

#include "Hook.h"



Hook::Hook() : currentDirection(0){
	texture.loadFromFile("img/hook.png");
	sprite.setTexture(texture);
	sprite.setPosition(300,300);
}

Hook::~Hook(){
	
}

void Hook::update(){
	
	sprite.setRotation(sin(currentDirection)*90+90);
	currentDirection += 0.001f;
}

void Hook::draw(RenderWindow &window){
	window.draw(sprite);

}