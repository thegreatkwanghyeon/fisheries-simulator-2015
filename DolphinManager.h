#ifndef __dManager__
#define __dManager__
#include "stdafx.h"
#include "Dolphin.h"

using namespace sf;
using namespace std;

class DolphinManager{
private :
	vector<Dolphin*> dolphinList;
	const int numberOfDolphin;//ȭ�鿡 ������ ������ ��
public :
	DolphinManager();
	~DolphinManager();
	void update();
	void draw(RenderWindow &window);
};

#endif