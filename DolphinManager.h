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
	const int numberOfDolphin;//화면에 존재할 돌고래의 수
	Hook* hook;
	unsigned int difficulty;
	bool isScore;
	float score;
	Well512 random;
public :
	DolphinManager(unsigned int _difficulty);
	~DolphinManager();
	void update();
	void draw(RenderWindow &window);

	void setHook(Hook* _hook);
	float getScore();
	void setDifficulty(unsigned int _diff){difficulty = _diff;};
};

#endif