#include "DolphinManager.h"

DolphinManager::DolphinManager() : numberOfDolphin(5){
	for(int i=0;i<numberOfDolphin;i++){
		dolphinList.push_back(new Dolphin("img/dolphin.png",true,0.5f*(float)(i+1)));
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
	}
}
void DolphinManager::draw(RenderWindow &window){
	for(vector<Dolphin*>::iterator it = dolphinList.begin();it!=dolphinList.end();++it){
		(*(it))->draw(window);
	}
}