#ifndef __dManager__
#define __dManager__
#include "stdafx.h"
#include "Dolphin.h"

using namespace sf;
using namespace std;

class DolphinManager{
private :
	vector<Dolphin*> dolphinList;
	const int numberOfDolphin;//화면에 존재할 돌고래의 수
public :
	DolphinManager();
	~DolphinManager();
	void update();
	void draw(RenderWindow &window);
};

#endif