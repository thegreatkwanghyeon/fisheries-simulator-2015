#include "TitleScene.h"
#include "Director.h"

TitleScene::TitleScene(){
	hook = new Hook();
}
TitleScene::~TitleScene(){

}
void TitleScene::update(){
	hook->update();
	
}
void TitleScene::draw(RenderWindow &window){
	hook->draw(window);

}
