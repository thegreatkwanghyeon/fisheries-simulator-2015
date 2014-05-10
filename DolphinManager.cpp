#include "DolphinManager.h"
#include <stdlib.h>
#include <time.h>

DolphinManager::DolphinManager() : numberOfDolphin(5){
	srand(time(NULL));
	for(int i=0;i<numberOfDolphin;i++){
		if(rand()%2){
			dolphinList.push_back(new Dolphin(random.Next(1,4),false,1.0f-(random.Next()%5)*0.1));
			dolphinList[i]->setPosition(Vector2f(-100,(random.Next()%400)+200));
		}else{
			dolphinList.push_back(new Dolphin(random.Next(1,4),false,1.0f-(random.Next()%5)*0.1));
			dolphinList[i]->setPosition(Vector2f(900,(random.Next()%400)+200));
		}
	}
	isScore=false;
}
DolphinManager::~DolphinManager(){
	for(vector<Dolphin*>::iterator it = dolphinList.begin();it!=dolphinList.end();++it){
		delete *(it);
	}
}
void DolphinManager::update(){
	srand(time(NULL));
	if (hook->getHookable()){//���� �̿밡���� ���
		for (vector<Dolphin*>::iterator it = dolphinList.begin(); it != dolphinList.end(); ++it){
			if (hook->getHookable() && !(*(it))->getDead() && BoundingBoxTest((*(it)), hook)){//���� ��밡�ɼ��� �ٽ� �ѹ� ���켭 ��Ÿ���� �����غ�...�׽�Ʈ
				(*(it))->setDead();
				hook->setShrinkSpeed(0.91f + (*(it))->getSize()*0.08);
				printf("hook speed : %.5f\n",0.91f + (*(it))->getSize()*0.08);
				hook->shrink();
				break;
			}
		}
	}
	for(vector<Dolphin*>::iterator it = dolphinList.begin();it!=dolphinList.end();++it){
		(*(it))->update();
		if((*(it))->getDead()){
			(*(it))->setPosition(hook->getEndPoint());
			if(hook->getState()){
				isScore=true;
				score=(*(it))->getSize()*149.0f;
				delete *(it);
				it--;
				dolphinList.erase(it+1);
				continue;
				//-----
			}
		}
		if((*(it))->getPosition().x < -100 || (*(it))->getPosition().x > 1000){
			//isScore=true;
			delete *(it);
			it--;
			dolphinList.erase(it+1);
			//-----
		}
	}
	for(int i=dolphinList.size();i<numberOfDolphin;i++){
		if(rand()%2){
			dolphinList.push_back(new Dolphin(random.Next(1,4),true,1.0f-(random.Next()%5)*0.1));
			dolphinList[i]->setPosition(Vector2f(-100,(random.Next()%400)+200));
		}else{
			dolphinList.push_back(new Dolphin(random.Next(1,4),false,1.0f-(random.Next()%5)*0.1));
			dolphinList[i]->setPosition(Vector2f(900,(random.Next()%400)+200));
		}
	}
}
void DolphinManager::draw(RenderWindow &window){
	for(vector<Dolphin*>::iterator it = dolphinList.begin();it!=dolphinList.end();++it){
		(*(it))->draw(window);
	}
}
void DolphinManager::setHook(Hook* _hook){
	hook = _hook;
}
float DolphinManager::getScore(){
	if(isScore){
		isScore=false;
		return score;
	}
	return false;
}