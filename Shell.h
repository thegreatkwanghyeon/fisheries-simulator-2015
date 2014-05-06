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
public:
	Shell();
	~Shell();
	void update();
	void draw(RenderWindow &window);
};

#endif