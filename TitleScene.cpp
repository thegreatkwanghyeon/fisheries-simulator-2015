#include "TitleScene.h"

TitleScene::TitleScene(){
	texture.loadFromFile("img/title.png");
	sprite.setTexture(texture);

	startButton = new Button("img/button.png");
	startButton->setPosition(450,330);
	startButton->setText("START",14);
	endButton = new Button("img/button.png");
	endButton->setPosition(450,450);
	endButton->setText("END",14);
}
TitleScene::~TitleScene(){
	delete endButton;
	delete startButton;
}
void TitleScene::update(){
	startButton->update();
	endButton->update();

	if (startButton->checkMouseClick())
		Director::getInstance()->pushScene(new StageScene());
	//else if (endButton->checkMouseClick())
	//	Director::getInstance()->freeInstance();
}
void TitleScene::draw(RenderWindow &window){
	window.draw(sprite);
	startButton->draw(window);
	endButton->draw(window);
}