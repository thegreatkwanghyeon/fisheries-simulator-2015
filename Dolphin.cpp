#include "Dolphin.h"

Dolphin::Dolphin(String _path,String _deadPath, bool _direction, float _size){
	printf("%.2f\n",_size);
	texture.loadFromFile(_path);
	deadTexture.loadFromFile(_deadPath);
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);

	direction = _direction;
	if(direction)
		sprite.setScale(-_size,_size);
	else
		sprite.setScale(_size,_size);
	delta.restart();
	speed=1.0+(1.0-_size)*2.0;
	isDead=false;
	size=_size;
}
Dolphin::~Dolphin(){
}
void Dolphin::update(){
	if(isDead)
		return;
	if(delta.getElapsedTime().asSeconds() >= 0.001){
		if(direction)
			setPosition(Vector2f(getPosition().x+speed,getPosition().y));
		else
			setPosition(Vector2f(getPosition().x-speed,getPosition().y));
		delta.restart();
	}
}
void Dolphin::draw(sf::RenderWindow &window){
	window.draw(sprite);
}
void Dolphin::setPosition(Vector2f _pos){
	sprite.setPosition(_pos);
}
Vector2f Dolphin::getPosition(){
	return sprite.getPosition();
}
void Dolphin::setDead(){
	sprite.setTexture(deadTexture);
	isDead=true;
}
bool Dolphin::getDead(){
	return isDead;
}