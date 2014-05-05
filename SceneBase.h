#ifndef __SCENEBASE_H__
#define __SCENEBASE_H__

#include "stdafx.h"

class SceneBase{
	private:

	public:

		SceneBase();

		virtual ~SceneBase();

		virtual void update()=0;
		virtual void draw(sf::RenderWindow& window)=0;
		virtual int changeScene();

};

#endif