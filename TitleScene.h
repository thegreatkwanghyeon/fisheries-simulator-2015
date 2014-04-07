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

	public:
		TitleScene();
		~TitleScene();
		void update();
		void draw(RenderWindow &window);
		int changeScene();
};

#endif