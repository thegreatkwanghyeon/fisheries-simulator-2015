#include "DolphinManager.h"
#include <stdlib.h>
#include <time.h>

DolphinManager::DolphinManager() : numberOfDolphin(5){
	srand(time(NULL));
	for(int i=0;i<numberOfDolphin;i++){
		if(rand()%2){
			dolphinList.push_back(new Dolphin("img/dolphin.png","img/dolphinDead.png",true,1.0f-(rand()%3)*0.1));
			dolphinList[i]->setPosition(Vector2f(-100,5*(rand()%100)+100));
		}else{
			dolphinList.push_back(new Dolphin("img/dolphin.png","img/dolphinDead.png",false,1.0f-(rand()%3)*0.1));
			dolphinList[i]->setPosition(Vector2f(900,5*(rand()%100)+100));
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
	if (hook->getHookable()){//훅을 이용가능한 경우
		for (vector<Dolphin*>::iterator it = dolphinList.begin(); it != dolphinList.end(); ++it){
			if (!(*(it))->getDead() && BoundingBoxTest((*(it)), hook)){
				(*(it))->setDead();
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
				score=(*(it))->getSize()*50.0f;
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
			dolphinList.push_back(new Dolphin("img/dolphin.png","img/dolphinDead.png",true,1.0f-(rand()%3)*0.1));
			dolphinList[i]->setPosition(Vector2f(-100,5*(rand()%100)+100));
		}else{
			dolphinList.push_back(new Dolphin("img/dolphin.png","img/dolphinDead.png",false,1.0f-(rand()%3)*0.1));
			dolphinList[i]->setPosition(Vector2f(900,5*(rand()%100)+100));
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
int DolphinManager::getScore(){
	if(isScore){
		isScore=false;
		return score;
	}
	return false;
}