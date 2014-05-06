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

typedef struct stage{
	Button *button;
	unsigned int highScore;
} Stage;

class StageScene : public SceneBase{
private:
	vector<Button*> buttons;
	vector<unsigned int> highScore;
	vector<Stage> stages;
	Texture texWorldMap;
	Sprite spWorldMap;

public:

	
	StageScene();
	~StageScene();
	void update();
	void draw(RenderWindow &window);
};

#endif