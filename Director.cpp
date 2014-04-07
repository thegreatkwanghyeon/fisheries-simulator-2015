#include "Director.h"

Director* Director::pInstance = NULL;

Director::Director(){

}

Director::~Director(){
	for(std::vector<SceneBase*>::iterator it = sceneList.begin();it!=sceneList.end();++it){
		delete *(it);
		sceneList.erase(it);
		--it;
	}
}

Director* Director::getInstance(){
	if (NULL == pInstance){

		pInstance = new Director();

	}

	return pInstance;
}

void Director::freeInstance(){

	if (NULL != pInstance){
		delete pInstance;
		pInstance = NULL;

	}
}

void Director::pushScene(SceneBase* scene){
	sceneList.push_back(scene);
}

void Director::popScene(){
	delete sceneList.back();
	sceneList.pop_back();
}

void Director::replaceScene(SceneBase* scene){
	//delete sceneList.back();
	sceneList.push_back(scene);
}

void Director::update(){
	sceneList.back()->update();
}

void Director::draw(sf::RenderWindow& window){
	sceneList.back()->draw(window);
}
void Director::setNewScene(){
    if(sceneList.size() <= 1)
        return;
    delete sceneList[0];
    sceneList.erase(sceneList.begin());
}
