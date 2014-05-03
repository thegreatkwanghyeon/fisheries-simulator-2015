#ifndef __earningmanager__
#define __earningmanager__

#include "stdafx.h"
using namespace sf;
using namespace std;

class EarningManager{
private:
	//점수에 관련 된 것들
	unsigned int currentEarning;//실제 데이터 값
	unsigned int visualEarning; //화면에 보이는 숫자

	//화면에 표시하기 위한 것들
	Font font;
	Text earning;

public:
	EarningManager();
	~EarningManager();
	void update();
	void draw(RenderWindow &window);

	void increaseEarning(unsigned int value);
	unsigned int getEarning();

};
#endif