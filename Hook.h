#ifndef __HOOK_H__
#define __HOOK_H__

#include "stdafx.h"
#include "cmath"
#include "hookhead.h"

using namespace sf;
using namespace std;

class Hook{
	private:
		//이미지 처리
		Texture texture;
		Sprite sprite;

		//위치와 방향 계산
		float currentAngle;  //삼각함수에 인수로 들어갈 각도 값
		float rotatedAngle;  //실제 연산을 거쳐 hook 이미지가 회전된 각도 값
		Vector2f currentPosition;
		const float movementConstant;  //프레임당 currentAngle 이 증가되는 값. 높을수록 hook 이미지가 빠르게 회전됨
		Transform* rotationTransform;
		Vector2f endPoint; //갈고리 대가리가 위치하는 지점
		bool isRotatable; 
		float scaleRatio;

		//윈도우 사이즈 계산
		int screenWidth;
		int screenHeight;

		//Delta time 계산
		Clock deltaClock;

		//Hookhead 관련
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

		Vector2f getEndPoint(); //Hookhead 가 존재해야 할 부분의 좌표값을 넘겨줌

};



#endif