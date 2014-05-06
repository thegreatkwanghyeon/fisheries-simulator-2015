#include "StageScene.h"
#include "Director.h"

StageScene::StageScene(){

	texWorldMap.loadFromFile("img/worldMap.png");
	spWorldMap.setTexture(texWorldMap);


	for(int i=0; i<6; ++i){
		stage temp = {new Button("img/buttonBlack.png"), 0};
		stages.push_back(temp);

	}

	
	for(auto iter=stages.begin(); iter!=stages.end(); iter++){
		iter->button->setPosition(20,20);
		iter->button->setText(to_string(iter->highScore),14);
	}

	stages.at(0).button->setPosition(0,0);
	stages.at(1).button->setPosition(100,0);
	stages.at(2).button->setPosition(200,0);
	stages.at(3).button->setPosition(0,100);
	stages.at(4).button->setPosition(0,200);
	stages.at(5).button->setPosition(500,350);


}

StageScene::~StageScene(){
	for(auto iter=stages.begin(); iter!=stages.end(); iter++){
		delete iter->button;
	}




}

void StageScene::update(){


	
	for(auto iter=stages.begin(); iter != stages.end(); iter++){
		iter->button->update();
		iter->button->setText(to_string(iter->highScore),14);

		if(iter->button->checkMouseClick()){
			Director::getInstance()->pushScene(new GameScene((unsigned int &)iter->highScore, (unsigned int)3));
		}

		if(iter->highScore > 50){
			iter->button->setTexture("img/buttonBronze.png");
		}
		if(iter->highScore > 100){
			iter->button->setTexture("img/buttonSilver.png");
		}
		if(iter->highScore > 150){
			iter->button->setTexture("img/buttonGold.png");
		}
	}

	




}

void StageScene::draw(RenderWindow &window){
	window.draw(spWorldMap);
	for(auto iter=stages.begin(); iter!=stages.end(); iter++){
		iter->button->draw(window);
	}
	
}
