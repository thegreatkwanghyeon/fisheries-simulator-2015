#include "StageScene.h"
#include "Director.h"

StageScene::StageScene(){

	texWorldMap.loadFromFile("img/worldMap.png");
	spWorldMap.setTexture(texWorldMap);


	for(int i=0; i<6; ++i){
		stage temp = {new Button("img/buttonBlack.png"), 0};
		stages.push_back(temp);

	}

	
	for(vector<Stage>::iterator iter=stages.begin(); iter!=stages.end(); iter++){
		//iter->button->setPosition(20,20);
		//iter->button->setOrigin(25,75);
		iter->button->setText(to_string(iter->highScore),14, Vector2f(0,50));
		iter->button->setTextColor(Color(0,0,0));
	}

	stages.at(0).button->setPosition(50-25,150-75);
	stages.at(1).button->setPosition(250-25,200-75);
	stages.at(2).button->setPosition(350-25,200-75);

	stages.at(3).button->setPosition(400-25,300-75);
	stages.at(4).button->setPosition(600-25,100-75);
	stages.at(5).button->setPosition(350-25,550-75);


}

StageScene::~StageScene(){
	for(vector<Stage>::iterator iter=stages.begin(); iter!=stages.end(); iter++){
		delete iter->button;
	}




}

void StageScene::update(){


	
	for(vector<Stage>::iterator iter=stages.begin(); iter != stages.end(); iter++){
		iter->button->update();
		iter->button->setText(to_string(iter->highScore),14,Vector2f(0,50));

		if(iter->button->checkMouseClick()){
			Director::getInstance()->pushScene(new GameScene((unsigned int &)iter->highScore, (unsigned int)(iter-stages.begin()+1)));
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
	for(vector<Stage>::iterator iter=stages.begin(); iter!=stages.end(); iter++){
		iter->button->draw(window);
	}
	
}
