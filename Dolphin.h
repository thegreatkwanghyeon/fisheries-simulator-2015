#ifndef __dolphin__
#define __dolphin__

#include "stdafx.h"
using namespace sf;
using namespace std;

class Dolphin{
private :
	Sprite sprite;
	Texture texture;
	bool direction;
	Clock delta;

	float speed;
public:
	Dolphin(String _path, bool _direction, float _speed);
	~Dolphin();

	void update();
	void draw(RenderWindow &window);

	void setPosition(Vector2f _pos);
	Vector2f getPosition();
};

#endif