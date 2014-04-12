/*
 *  Date: 2014-04-12
 *	Version: 1.0
 */

#ifndef __HOOK_H__
#define __HOOK_H__

#include "stdafx.h"
#include "cmath"

using namespace sf;
using namespace std;

class Hook{
	private:
		//Images
		Texture texture;
		Sprite sprite;

		//Position Calculations
		float currentDirection;
		Vector2f currentPosition;

	public:
		Hook();
		~Hook();
		void update();
		void draw(RenderWindow &window);

};



#endif