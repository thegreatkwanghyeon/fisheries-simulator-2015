#ifndef __dolphin__
#define __dolphin__

#include "stdafx.h"
using namespace sf;
using namespace std;

class Dolphin{
private :
	Sprite sprite;
	Texture texture,deadTexture;
	bool direction;
	Clock delta;

	float speed;

	bool isDead;
public:
	Dolphin(String _path, String _deadPath ,bool _direction, float _speed);
	~Dolphin();

	void update();
	void draw(RenderWindow &window);

	void setPosition(Vector2f _pos);
	Vector2f getPosition();
	const Transform& getTransform()const{ return sprite.getTransform(); }
	const IntRect& getTextureRect()const{ return sprite.getTextureRect(); }

	void setDead();
	bool getDead();
};

#endif