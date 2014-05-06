#include "GameScene.h"
#include "Director.h"

GameScene::GameScene(unsigned int &score) : difficulty(1){
	texUnderwater.loadFromFile("img/underwater.png");
	spUnderwater.setTexture(texUnderwater);
	hook = new Hook();
	dol = new DolphinManager();
	earningManager = new EarningManager();
	timeManager = new TimeManager();
	dol->setHook(hook);
}

GameScene::GameScene(unsigned int &score, unsigned int difficulty){
	texUnderwater.loadFromFile("img/underwater.png");
	spUnderwater.setTexture(texUnderwater);
	hook = new Hook();
	dol = new DolphinManager();
	earningManager = new EarningManager();
	timeManager = new TimeManager();
	dol->setHook(hook);
	highScore = &score;
	this->difficulty = difficulty;
}


GameScene::~GameScene(){
	if((*highScore)<earningManager->getEarning())
		*(highScore) = earningManager->getEarning();
	delete dol;
	delete hook;
	delete earningManager;
}
void GameScene::update(){
	hook->update();
	dol->update();
	earningManager->update();
	timeManager->update();


	if(dol->isGetScore()){
		earningManager->increaseEarning(50);
	}

	if(Keyboard::isKeyPressed(Keyboard::BackSpace)){
		Director::getInstance()->popScene();
	}

	
}
void GameScene::draw(RenderWindow &window){
	window.draw(spUnderwater);
	hook->draw(window);
	dol->draw(window);
	earningManager->draw(window);
	timeManager->draw(window);
}
int GameScene::changeScene(){
	return -1;
}