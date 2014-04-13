/*
 *  Date: 2014-04-13
 *	Version: 1.1
 */

#include "Hook.h"

Hook::Hook() : currentAngle(0), movementConstant(3.33f){
	texture.loadFromFile("img/hook.png");
	sprite.setTexture(texture);
	sprite.setOrigin(0,sprite.getGlobalBounds().height/2);
	sprite.setPosition(300,300);
	rotationTransform = new Transform();
}

Hook::~Hook(){
	delete rotationTransform;
}

void Hook::update(){
	rotatedAngle = (cos(currentAngle)+sin(currentAngle))*60+90;
	sprite.setRotation(rotatedAngle);
	currentAngle += movementConstant*deltaClock.getElapsedTime().asSeconds();

	deltaClock.restart();
}

void Hook::draw(RenderWindow &window){
	window.draw(sprite);
}

Vector2f Hook::getSize(){
	return Vector2f(sprite.getGlobalBounds().width,sprite.getGlobalBounds().height);
}

Vector2f Hook::getPosition(){
	return sprite.getPosition();
}

float Hook::getRotatedAngle(){
	return rotatedAngle;
}

Vector2f Hook::getEndPoint(){
	Vector2f tempPosition = sprite.getPosition();
	tempPosition.y += sprite.getLocalBounds().width; //회전하기 전의 hook 의 끝부분 좌표

	rotationTransform->rotate(rotatedAngle-90,getPosition()); //hook 이 기울어진 만큼 회전변환 해준다.
	tempPosition = rotationTransform->transformPoint(tempPosition);
	rotationTransform->rotate(-rotatedAngle-90,getPosition()); //Transform 의 회전각을 제자리로 되돌림

	return tempPosition;

}