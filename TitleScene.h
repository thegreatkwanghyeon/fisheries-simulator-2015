#ifndef __TITLESCENE_H__
#define __TITLESCENE_H__

#include "SceneBase.h"
#include "Global.h"
#include "stdafx.h"
#include "Button.h"
#include "Director.h"
#include "StageScene.h"

using namespace sf;
using namespace std;

class TitleScene : public SceneBase{
	private:
		Sprite sprite;
		Texture texture;
		Button* startButton;
		Button* endButton;
	public:
		TitleScene();
		~TitleScene();
		void update();
		void draw(RenderWindow &window);
};

#endif