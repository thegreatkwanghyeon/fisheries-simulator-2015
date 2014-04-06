#ifndef __TITLESCENE_H__
#define __TITLESCENE_H__

#include "SceneBase.h"
#include "Global.h"
#include "stdafx.h"

using namespace sf;

enum{
	centerScene,intervalScene,preScene,normalScene
};

class TitleScene : public SceneBase{
	private:
		EyeButton* startButton;
		EyeButton* introButton;

		Texture bgTexture;
		Texture eyeTexture;
		Sprite bg;
		Sprite eye;

		Font font;
		Text text;
		RectangleShape rec;
		int alpha;

		int state;
		bool keyPress;
	public:
		TitleScene();
		~TitleScene();
		void update();
		void draw(RenderWindow &window);
		int changeScene();
};

#endif