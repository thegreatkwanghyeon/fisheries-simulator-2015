#include "StageScene.h"
#include "Director.h"

StageScene::StageScene():testtesttest(0){

	for(int i=0; i<1; ++i){
		buttons.push_back(new Button("img/stageButton.png"));
		highScore.push_back(0);
	}

	for(auto iter=buttons.begin(); iter!=buttons.end(); iter++){
		(*iter)->setPosition(20,20);
		(*iter)->setText(to_string(testtesttest),14);
	}



}

StageScene::~StageScene(){
	for(auto iter=buttons.begin(); iter!=buttons.end(); iter++){
		delete *iter;
	}


}

void StageScene::update(){
	for(auto iter=buttons.begin(); iter!=buttons.end(); iter++){
		(*iter)->update();
		(*iter)->setText(to_string(testtesttest),14);
		
		if((*iter)->checkMouseClick()){
			Director::getInstance()->pushScene(new GameScene((unsigned int &)testtesttest, (unsigned int)3));
		}
	}





}

void StageScene::draw(RenderWindow &window){
	for(auto iter=buttons.begin(); iter!=buttons.end(); iter++){
		(*iter)->draw(window);
	}
}
