/*
 *  Date: 2014-04-13
 *	Version: 1.0
 */

#ifndef __HOOKHEAD_H__
#define __HOOKHEAD_H__

#include "stdafx.h"
#include "cmath"

using namespace sf;
using namespace std;

class Hookhead{
	private:
		//이미지 처리
		Texture texture;
		Sprite sprite;

		//위치와 방향 계산
		float currentAngle;
		Vector2f currentPosition;
		const float movementConstant;


	public:

		Hookhead();
		~Hookhead();
		void update();
		void draw(RenderWindow &window);

		void setPosition(Vector2f position); //Hook 에서 가져온 현재 hookhead의 위치
		void setRotatedAngle(float rotatedAngle);

		const Transform& getTransform()const{ return sprite.getTransform(); }
		const IntRect& getTextureRect()const{ return sprite.getTextureRect(); }

};

#endif