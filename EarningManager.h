#ifndef __earningmanager__
#define __earningmanager__

#include "stdafx.h"
using namespace sf;
using namespace std;

class EarningManager{
private:
	//������ ���� �� �͵�
	unsigned int currentEarning;//���� ������ ��
	unsigned int visualEarning; //ȭ�鿡 ���̴� ����

	//ȭ�鿡 ǥ���ϱ� ���� �͵�
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