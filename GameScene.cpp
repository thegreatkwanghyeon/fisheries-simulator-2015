#include "GameScene.h"
#include "Director.h"

GameScene::GameScene(){
	hook = new Hook();
	dol = new DolphinManager();
	earningManager = new EarningManager();
	dol->setHook(hook);
	
}
GameScene::~GameScene(){
	delete dol;
	delete hook;
	delete earningManager;
}
void GameScene::update(){
	hook->update();
	dol->update();
	earningManager->update();


	if(dol->isGetScore()){
		earningManager->increaseEarning(50);
	}

	
}
void GameScene::draw(RenderWindow &window){
	hook->draw(window);
	dol->draw(window);
	earningManager->draw(window);
}
int GameScene::changeScene(){
	return -1;
}