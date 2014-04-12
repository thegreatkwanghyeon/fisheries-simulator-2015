/*
 *  Date: 2014-04-12
 *	Version: 1.0
 */

#include "Hook.h"



Hook::Hook(){
	texture.loadFromFile("img/hook.png");
	sprite.setTexture(texture);
}

Hook::~Hook(){
}

void Hook::update(){
}

void Hook::draw(RenderWindow &window){
	window.draw(sprite);

}