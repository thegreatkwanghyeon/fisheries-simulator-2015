/*
 *  Date: 2014-04-13
 *	Version: 1.0
 */

#include "Hookhead.h"

Hookhead::Hookhead() : movementConstant(0.035f){
	texture.loadFromFile("img/hookhead.png");
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().width/2.0f, sprite.getLocalBounds().height/2.0f);
}

Hookhead::~Hookhead(){
}

void Hookhead::update(){
	sprite.setPosition(currentPosition);
	sprite.setRotation(currentAngle);
}

void Hookhead::draw(RenderWindow &window){
	window.draw(sprite);
}

void Hookhead::setPosition(sf::Vector2f position){
	currentPosition = position;
}

void Hookhead::setRotatedAngle(float rotatedAngle){
	currentAngle = rotatedAngle;
}