#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__

#include "SceneBase.h"
#include "Global.h"
#include "stdafx.h"
#include "Hook.h"
#include "DolphinManager.h"
#include "EarningManager.h"

using namespace sf;
using namespace std;

class GameScene : public SceneBase{
	private:

		Hook *hook;
		DolphinManager *dol;
		EarningManager *earningManager;

	public:
		GameScene();
		~GameScene();
		void update();
		void draw(RenderWindow &window);
		int changeScene();
};

#endif