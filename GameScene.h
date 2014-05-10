#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__

#include "SceneBase.h"
#include "Global.h"
#include "stdafx.h"
#include "Hook.h"
#include "DolphinManager.h"
#include "EarningManager.h"
#include "TimeManager.h"
#include "Button.h"
#include "Shell.h"
#include "Collision.h"

using namespace sf;
using namespace std;

class GameScene : public SceneBase{
	private:

		Hook *hook;
		Button* endButton;
		DolphinManager *dol;
		Shell *shell;
		EarningManager *earningManager;
		TimeManager *timeManager;
		unsigned int *highScore;
		unsigned int difficulty;

		Texture texUnderwater;
		Sprite spUnderwater;

		Clock bulletClock;

		bool isEnd;
		bool bulletTime;
		void endGame();

		//아래는 쉐이더 관련...
		Shader shader;
		Texture drawingTex;
		Image drawingBuffer;
		Sprite drawingSprite;

	public:
		GameScene(unsigned int &test);
		GameScene(unsigned int &score, unsigned int difficulty);
		~GameScene();
		void update();
		void draw(RenderWindow &window);
		int changeScene();
};

#endif