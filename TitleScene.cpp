#include "TitleScene.h"
#include "Director.h"

TitleScene::TitleScene(){
	hook = new Hook();
	dol = new DolphinManager();
	earningManager = new EarningManager();
	dol->setHook(hook);
	
}
TitleScene::~TitleScene(){
	delete dol;
	delete hook;
	delete earningManager;
}
void TitleScene::update(){
	hook->update();
	dol->update();
	earningManager->update();


	if(Keyboard::isKeyPressed(Keyboard::Return)){
		earningManager->increaseEarning(50);
	}

	
}
void TitleScene::draw(RenderWindow &window){
	hook->draw(window);
	dol->draw(window);
	earningManager->draw(window);
}
