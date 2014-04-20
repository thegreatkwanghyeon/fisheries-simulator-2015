#include "TitleScene.h"
#include "Director.h"

TitleScene::TitleScene(){
	hook = new Hook();
	dol = new DolphinManager();
	//dol->setPosition(Vector2f(100,100));
}
TitleScene::~TitleScene(){
	delete dol;
	delete hook;
}
void TitleScene::update(){
	hook->update();
	dol->update();
	
}
void TitleScene::draw(RenderWindow &window){
	hook->draw(window);
	dol->draw(window);

}
