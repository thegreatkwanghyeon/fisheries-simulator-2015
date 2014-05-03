#ifndef __SCENEBASE_H__
#define __SCENEBASE_H__

#include "stdafx.h"

class SceneBase{
	private:

	public:

		SceneBase();

		virtual ~SceneBase();

		virtual void update();
		virtual void draw(sf::RenderWindow& window);
		virtual int changeScene();

};

#endif