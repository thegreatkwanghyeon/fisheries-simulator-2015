#ifndef __shell__
#define __shell__

#include "stdafx.h"
#include "Global.h"

using namespace sf;
using namespace std;

class Shell{
private:
	Texture texOpenedShell;
	Texture texClosedShell;
	Sprite spShell;

	bool chkOpen,isDead;

	Clock clock,everyClock;
public:
	Shell();
	~Shell();
	void update();
	void draw(RenderWindow &window);

	const Transform& getTransform()const{ return spShell.getTransform(); }
	const IntRect& getTextureRect()const{ return spShell.getTextureRect(); }

	bool getCollision(){return chkOpen;}
	void setPosition(Vector2f _pos);

	void setDead(bool _dead);
	bool getDead();
};

#endif