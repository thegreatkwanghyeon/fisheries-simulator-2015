#ifndef __shell__
#define __shell__

#include "stdafx.h"

using namespace sf;
using namespace std;

class Shell{
private:
	Texture texOpenedShell;
	Texture texClosedShell;
	Sprite spShell;

	bool chkOpen;

	Clock clock,everyClock;
public:
	Shell();
	~Shell();
	void update();
	void draw(RenderWindow &window);

	const Transform& getTransform()const{ return spShell.getTransform(); }
	const IntRect& getTextureRect()const{ return spShell.getTextureRect(); }

};

#endif