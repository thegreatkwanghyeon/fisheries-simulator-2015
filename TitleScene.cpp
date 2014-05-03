#include "TitleScene.h"
#include "Director.h"

TitleScene::TitleScene(){
	texture.loadFromFile("img/title.png");
	sprite.setTexture(texture);

	sButton = new Button("img/button.png");
	sButton->setPosition(200,200);
	sButton->setText("START",14);
	eButton = new Button("img/button.png");
	eButton->setPosition(200,400);
	eButton->setText("END",14);
}
TitleScene::~TitleScene(){
	delete eButton;
	delete sButton;
}
void TitleScene::update(){
	sButton->update();
	eButton->update();
}
void TitleScene::draw(RenderWindow &window){
	window.draw(sprite);
	sButton->draw(window);
	eButton->draw(window);
}
int TitleScene::changeScene(){
	if(sButton->checkMouseClick())
		return 2;
	else if(eButton->checkMouseClick())
		return 0;
	return -1;
}