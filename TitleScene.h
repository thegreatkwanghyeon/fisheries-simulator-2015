#ifndef __TITLESCENE_H__
#define __TITLESCENE_H__

#include "SceneBase.h"
#include "Global.h"
#include "stdafx.h"
#include "Hook.h"
#include "DolphinManager.h"
#include "EarningManager.h"

using namespace sf;

enum{
	centerScene,intervalScene,preScene,normalScene
};

class TitleScene : public SceneBase{
	private:

		Hook *hook;
		DolphinManager *dol;
		EarningManager *earningManager;

	public:
		TitleScene();
		~TitleScene();
		void update();
		void draw(RenderWindow &window);
		int changeScene();
};

#endif