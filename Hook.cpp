/*
 *  Date: 2014-04-20
 *	Version: 1.2
 */

#include "Hook.h"

Hook::Hook() : currentAngle(0), rotatedAngle(0), movementConstant(3.33f), isRotatable(true), scaleRatio(1.0f), screenWidth(800), screenHeight(600), hookable(true){
	texture.loadFromFile("img/hook.png");
	sprite.setTexture(texture);
	sprite.setOrigin(0,sprite.getGlobalBounds().height/2);
	sprite.setPosition(400,0);
	rotationTransform = new Transform();
	hookhead = new Hookhead();
}

Hook::~Hook(){
	delete rotationTransform;
}

void Hook::update(){
	if(isRotatable){
		rotatedAngle = (cos(currentAngle)+sin(currentAngle))*60+90;
		currentAngle += movementConstant*deltaClock.getElapsedTime().asSeconds();
		sprite.setRotation(rotatedAngle);	
	}

	deltaClock.restart();

	
	hookhead->setPosition(getEndPoint());
	hookhead->setRotatedAngle(rotatedAngle-90);
	hookhead->update();
	sprite.scale(scaleRatio, 1.00f);

	if(sprite.getScale().x<=1.0f){
		doRotate();
		stopScale();
	}

	if(Keyboard::isKeyPressed(Keyboard::Down)){
		stretch();
		stopRotate();
	}

	if(outOfScreen()){
		shrink();
		stopRotate();
	}
	

}

void Hook::draw(RenderWindow &window){
	screenWidth = window.getSize().x;
	screenHeight = window.getSize().y;
	window.draw(sprite);
	hookhead->draw(window);
}

Vector2f Hook::getSize(){
	return Vector2f(sprite.getLocalBounds().width,sprite.getLocalBounds().height);
}

Vector2f Hook::getPosition(){
	return sprite.getPosition();
}

float Hook::getRotatedAngle(){
	return rotatedAngle;
}

Vector2f Hook::getEndPoint(){
	Vector2f tempPosition = sprite.getPosition();
	tempPosition.y += sprite.getLocalBounds().width * sprite.getScale().x; //회전하기 전의 hook 의 끝부분 좌표

	rotationTransform->rotate(rotatedAngle-90,getPosition()); //hook 이 기울어진 만큼 회전변환 해준다.
	tempPosition = rotationTransform->transformPoint(tempPosition);
	rotationTransform->rotate(-(rotatedAngle-90),getPosition()); //Transform 의 회전각을 제자리로 되돌림

	return tempPosition;

}

void Hook::stretch(){
	hookable = true;
	scaleRatio = 1.01f;
}

void Hook::shrink(){
	hookable = false;
	scaleRatio = 0.99f;
}

void Hook::stopScale(){
	hookable = false;
	scaleRatio = 1.0f;
}

void Hook::doRotate(){
	isRotatable = true;
}

void Hook::stopRotate(){
	isRotatable = false;
}

bool Hook::outOfScreen(){
	if((getEndPoint().x > screenWidth) || (getEndPoint().y > screenHeight) || (getEndPoint().x <= 0))
		return true;
	else
		return false;
}

bool Hook::getHookable(){
	return hookable;
}