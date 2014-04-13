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
		//�̹��� ó��
		Texture texture;
		Sprite sprite;

		//��ġ�� ���� ���
		float currentDirection;
		Vector2f currentPosition;
		const float movementConstant;


	public:

		Hookhead();
		~Hookhead();
		void update();
		void draw(RenderWindow &window);

};

#endif