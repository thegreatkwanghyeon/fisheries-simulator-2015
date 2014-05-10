#include "GameScene.h"
#include "Director.h"

GameScene::GameScene(unsigned int &score) : difficulty(1){
	texUnderwater.loadFromFile("img/underwater.png");
	spUnderwater.setTexture(texUnderwater);
	hook = new Hook();
	dol = new DolphinManager(1);
	earningManager = new EarningManager();
	timeManager = new TimeManager();
	dol->setHook(hook);

	shell = new Shell();

	isEnd=false;
	bulletTime=false;
	endButton = new Button("img/button.png");
	endButton->setPosition(270.0f,200.0f);
	endButton->setText("END",14);
}

GameScene::GameScene(unsigned int &score, unsigned int difficulty){
	texUnderwater.loadFromFile("img/underwater.png");
	spUnderwater.setTexture(texUnderwater);
	hook = new Hook();
	dol = new DolphinManager(difficulty);
	earningManager = new EarningManager();
	timeManager = new TimeManager();
	dol->setHook(hook);
	highScore = &score;
	this->difficulty = difficulty;

	shell = new Shell();

	isEnd=false;
	bulletTime=false;
	endButton = new Button("img/button.png");
	endButton->setPosition(270.0f,200.0f);
	endButton->setText("END",14);

}


GameScene::~GameScene(){
	if((*highScore)<earningManager->getEarning())
		*(highScore) = earningManager->getEarning();
	delete dol;
	delete hook;
	delete earningManager;
	if(shell != NULL)
		delete shell;
}
void GameScene::update(){
	int getScore;
	if(isEnd){
		endGame();
		return;
	}
	if(!hook->getHookable() && !bulletTime && Keyboard::isKeyPressed(Keyboard::Y)){
		printf("bulletTime 1/20\n");
		timeRatio=0.05f;
		bulletTime=true;
		bulletClock.restart();
	}else if(bulletTime && (hook->getHookable() == true || bulletClock.getElapsedTime().asSeconds() >= 5.0f)){
		timeRatio=1.0f;
		bulletTime=false;
	}
	hook->update();
	dol->update();
	earningManager->update();
	timeManager->update();

	getScore = (int)dol->getScore()*difficulty;
	if(getScore != 0){
		earningManager->increaseEarning(getScore);
	}

	if(Keyboard::isKeyPressed(Keyboard::BackSpace)){
		Director::getInstance()->popScene();
	}
	if(timeManager->getTime() <= 0.0f){
		isEnd=true;
	}
	if(shell != NULL){
		shell->update();
		if(shell->getDead() == true){
			shell->setPosition(hook->getEndPoint());
			if(hook->getState()){//훅이 본위치로 돌아간경우
				delete shell;
				shell=NULL;
				earningManager->increaseEarning(500*difficulty);
			}
		}else if(shell->getDead() == false && shell->getCollision() && BoundingBoxTest(shell,hook)){
			printf("collision!!! shell!!!\n");
			shell->setDead(true);
		}
	}
}
void GameScene::draw(RenderWindow &window){
	window.draw(spUnderwater);
	hook->draw(window);
	dol->draw(window);
	earningManager->draw(window);
	timeManager->draw(window);
	if(isEnd)
		endButton->draw(window);
	if(shell != NULL)
		shell->draw(window);
}
int GameScene::changeScene(){
	return -1;
}
void GameScene::endGame(){
	endButton->update();
	if(endButton->checkMouseClick())
		Director::getInstance()->popScene();

}