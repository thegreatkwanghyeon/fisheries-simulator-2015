#include "DolphinManager.h"
#include <stdlib.h>
#include <time.h>

DolphinManager::DolphinManager() : numberOfDolphin(5){
	srand(time(NULL));
	for(int i=0;i<numberOfDolphin;i++){
		if(rand()%2){
			dolphinList.push_back(new Dolphin("img/dolphin.png","img/dolphinDead.png",true,0.5f*(float)((rand()%5)+3)));
			dolphinList[i]->setPosition(Vector2f(-100,5*(rand()%100)+100));
		}else{
			dolphinList.push_back(new Dolphin("img/dolphin.png","img/dolphinDead.png",false,0.5f*(float)((rand()%5)+3)));
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
	for(vector<Dolphin*>::iterator it = dolphinList.begin();it!=dolphinList.end();++it){
		(*(it))->update();
		if((*(it))->getDead()){
			(*(it))->setPosition(hook->getEndPoint());
			if(hook->getState()){
				isScore=true;
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
	if(hook->getHookable()){//���� �̿밡���� ���
		for(vector<Dolphin*>::iterator it = dolphinList.begin();it!=dolphinList.end();++it){
			if( !(*(it))->getDead() && BoundingBoxTest( (*(it)),hook)){
				(*(it))->setDead();
				hook->shrink();
			}
		}
	}
	for(int i=dolphinList.size();i<numberOfDolphin;i++){
		if(rand()%2){
			dolphinList.push_back(new Dolphin("img/dolphin.png","img/dolphinDead.png",true,0.5f*(float)((rand()%5)+1)));
			dolphinList[i]->setPosition(Vector2f(-100,5*(rand()%100)+100));
		}else{
			dolphinList.push_back(new Dolphin("img/dolphin.png","img/dolphinDead.png",false,0.5f*(float)((rand()%5)+1)));
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
bool DolphinManager::isGetScore(){
	if(isScore){
		isScore=false;
		return true;
	}
	return false;
}