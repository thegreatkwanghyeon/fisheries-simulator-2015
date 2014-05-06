#ifndef __dManager__
#define __dManager__
#include "stdafx.h"
#include "Dolphin.h"
#include "Hook.h"
#include "Well512.h"
#include "collision.h"

using namespace sf;
using namespace std;

class DolphinManager{
private :
	vector<Dolphin*> dolphinList;
	const int numberOfDolphin;//ȭ�鿡 ������ ������ ��
	Hook* hook;
	bool isScore;
	float score;
	Well512 random;
public :
	DolphinManager();
	~DolphinManager();
	void update();
	void draw(RenderWindow &window);

	void setHook(Hook* _hook);
	int getScore();
};

#endif