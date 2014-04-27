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
		bool isRotatable; 
		float scaleRatio;

		//������ ������ ���
		int screenWidth;
		int screenHeight;

		//Delta time ���
		Clock deltaClock;

		//Hookhead ����
		Hookhead* hookhead;
		bool hookable;

		//Private memeber methods

		

	public:
		Hook();
		~Hook();
		void update();
		void draw(RenderWindow &window);

		Vector2f getSize();
		Vector2f getPosition();
		float getRotatedAngle();

		void stretch();
		void shrink();
		void stopScale();
		void doRotate();
		void stopRotate();

		bool outOfScreen();
		bool getHookable();

		const Transform& getTransform()const{ return hookhead->getTransform(); }
		const IntRect& getTextureRect()const{ return hookhead->getTextureRect(); }

		Vector2f getEndPoint(); //Hookhead �� �����ؾ� �� �κ��� ��ǥ���� �Ѱ���

};



#endif