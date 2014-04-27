#include "DolphinManager.h"

DolphinManager::DolphinManager() : numberOfDolphin(5){
	for(int i=0;i<numberOfDolphin;i++){
		dolphinList.push_back(new Dolphin("img/dolphin.png","img/dolphinDead.png",true,0.5f*(float)(i+1)));
		dolphinList[i]->setPosition(Vector2f(100,100*(i+1)));
	}
}
DolphinManager::~DolphinManager(){
	for(vector<Dolphin*>::iterator it = dolphinList.begin();it!=dolphinList.end();++it){
		delete *(it);
	}
}
void DolphinManager::update(){
	for(vector<Dolphin*>::iterator it = dolphinList.begin();it!=dolphinList.end();++it){
		(*(it))->update();
		if((*(it))->getDead())
			(*(it))->setPosition(hook->getEndPoint());
	}
	if(hook->getHookable()){//훅을 이용가능한 경우
		for(vector<Dolphin*>::iterator it = dolphinList.begin();it!=dolphinList.end();++it){
			if( !(*(it))->getDead() && BoundingBoxTest( (*(it)),hook)){
				(*(it))->setDead();
				hook->shrink();
			}
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