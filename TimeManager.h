#ifndef __timemanager__
#define __timemanager__

#include "stdafx.h"
using namespace sf;
using namespace std;

class TimeManager{
private:
	//�ð� ������
	float timeRemaining;
	Clock clock;
	
	//ȭ�鿡 ǥ���ϱ� ���� �ڷ�
	Font font;
	Text time;




public:
	TimeManager();
	~TimeManager();
	void update();
	void draw(RenderWindow &window);
	void setTime(float time);
	float getTime();
};


#endif
