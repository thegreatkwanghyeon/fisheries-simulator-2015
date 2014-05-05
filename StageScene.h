#ifndef __stagescene__
#define __stagescene__

#include "stdafx.h"
#include "SceneBase.h"
#include "Global.h"
#include "Button.h"
#include "Director.h"
#include "GameScene.h"

using namespace sf;
using namespace std;

class StageScene : public SceneBase{
private:
	vector<Button*> buttons;
	vector<unsigned int> highScore;

	int testtesttest;

public:

	
	StageScene();
	~StageScene();
	void update();
	void draw(RenderWindow &window);
};

#endif