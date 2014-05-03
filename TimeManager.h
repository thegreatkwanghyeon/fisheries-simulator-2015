#ifndef __timemanager__
#define __timemanager__

#include "stdafx.h"
using namespace sf;
using namespace std;

class TimeManager{
private:
	//시간 데이터
	float timeRemaining;
	Clock clock;
	
	//화면에 표시하기 위한 자료
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
