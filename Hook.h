/*
 *  Date: 2014-04-13
 *	Version: 1.1
 */

#ifndef __HOOK_H__
#define __HOOK_H__

#include "stdafx.h"
#include "cmath"
#include "hookhead.h"

using namespace sf;
using namespace std;

class Hook{
	private:
		//�̹��� ó��
		Texture texture;
		Sprite sprite;

		//��ġ�� ���� ���
		float currentAngle;  //�ﰢ�Լ��� �μ��� �� ���� ��
		float rotatedAngle;  //���� ������ ���� hook �̹����� ȸ���� ���� ��
		Vector2f currentPosition;
		const float movementConstant;  //�����Ӵ� currentAngle �� �����Ǵ� ��. �������� hook �̹����� ������ ȸ����
		Transform* rotationTransform;
		Vector2f endPoint; //���� �밡���� ��ġ�ϴ� ����

		//Delta time ���
		Clock deltaClock;

		//Hookhead ����
		Hookhead* hookhead;

		//Memeber methods
		Vector2f getEndPoint(); //Hookhead �� �����ؾ� �� �κ��� ��ǥ���� �Ѱ���

	public:
		Hook();
		~Hook();
		void update();
		void draw(RenderWindow &window);

		Vector2f getSize();
		Vector2f getPosition();
		float getRotatedAngle();

};



#endif