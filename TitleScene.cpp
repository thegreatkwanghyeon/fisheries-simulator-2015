#include "TitleScene.h"
#include "Director.h"
#include "GameScene.h"

TitleScene::TitleScene(){
	texture.loadFromFile("img/title.png");
	sprite.setTexture(texture);

	startButton = new Button("img/button.png");
	startButton->setPosition(200,200);
	startButton->setText("START",14);
	endButton = new Button("img/button.png");
	endButton->setPosition(200,400);
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
		Director::getInstance()->pushScene(new GameScene());
	else if (endButton->checkMouseClick())
		Director::getInstance()->popScene();
}
void TitleScene::draw(RenderWindow &window){
	window.draw(sprite);
	startButton->draw(window);
	endButton->draw(window);
}
int TitleScene::changeScene(){
	return -1;
}