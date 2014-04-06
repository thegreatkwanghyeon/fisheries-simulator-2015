#include "TitleScene.h"
#include "Director.h"

TitleScene::TitleScene(){
	startButton=new EyeButton("Image/EyeButton.png",Vector2f(100,100),"Start",1.5);
	startButton->setPosition(Vector2f((constants::INTERNAL_WIDTH / 2) - (constants::INTERNAL_WIDTH / 4), (constants::INTERNAL_HEIGHT / 2) + (constants::INTERNAL_HEIGHT / 4)));

	introButton = new EyeButton("Image/EyeButton.png", Vector2f(75, 75), L"Settings", 1.5);
	introButton->setPosition(Vector2f(constants::INTERNAL_WIDTH - (constants::INTERNAL_WIDTH / 4), (constants::INTERNAL_HEIGHT / 2) + (constants::INTERNAL_HEIGHT / 4)));

	bgTexture.loadFromFile("Image/eyeBG.png");
	bg.setTexture(bgTexture);

	eyeTexture.loadFromFile("Image/temp.png");
	eye.setTexture(eyeTexture);
	eye.setOrigin(50,50);
	eye.setPosition(Vector2f(constants::INTERNAL_WIDTH/2,constants::INTERNAL_HEIGHT/2));


	font.loadFromFile("Font/aPinoL.ttf");
	text.setFont(font);
	text.setCharacterSize(25);
	text.setString(L"Look at the button and press enter.");
	text.setOrigin(text.getLocalBounds().width/2,0);
	text.setPosition(constants::INTERNAL_WIDTH/2,(constants::INTERNAL_HEIGHT/2)-100);

	state=0;
	keyPress=false;
}
TitleScene::~TitleScene(){
	delete startButton;
	delete introButton;
}
void TitleScene::update(){
	Vector2i mouse = Mouse::getPosition();
	if(state == normalScene){
		startButton->update();
		introButton->update();
		if(Keyboard::isKeyPressed(Keyboard::Escape)){
			state=centerScene;

			bgTexture.loadFromFile("Image/eyeBG.png");

			text.setString(L"Look at the button and press enter.");
			text.setOrigin(text.getLocalBounds().width/2,0);
			text.setPosition(constants::INTERNAL_WIDTH/2,(constants::INTERNAL_HEIGHT/2)-100);

			eye.setPosition(Vector2f(constants::INTERNAL_WIDTH/2,constants::INTERNAL_HEIGHT/2));
			printf("next\n");
		}
	}
	if(!keyPress && state == centerScene && Keyboard::isKeyPressed(Keyboard::Return)){
		keyPress=true;
		state++;

		centerPoint.x=(float)mouse.x;
		centerPoint.y=(float)mouse.y;

		eye.setPosition(Vector2f(constants::INTERNAL_WIDTH/2-100,constants::INTERNAL_HEIGHT/2-100));
		text.setString(L"Great! And now look at the button and press enter again.");
		text.setOrigin(text.getLocalBounds().width/2,0);
		text.setPosition((constants::INTERNAL_WIDTH/2)-100,(constants::INTERNAL_HEIGHT/2)-200);
	}else if(!keyPress && state == intervalScene && Keyboard::isKeyPressed(Keyboard::Return)){
		rec.setSize(Vector2f(constants::INTERNAL_WIDTH,constants::INTERNAL_HEIGHT));
		alpha=0;
		rec.setFillColor(Color(0,0,0,alpha));

		keyPress=true;
		state++;

		intervalPoint.x=(float)mouse.x;
		intervalPoint.y=(float)mouse.y;

		text.setString(L"Press enter if you wanna play.");
		text.setOrigin(text.getLocalBounds().width/2,0);
		text.setPosition((constants::INTERNAL_WIDTH/2),(constants::INTERNAL_HEIGHT/2)-100);
	}else if(!keyPress && state == preScene &&  Keyboard::isKeyPressed(Keyboard::Return)){
		bgTexture.loadFromFile("Image/title.png");
		state++;
		keyPress=true;
	}
	if(!Keyboard::isKeyPressed(Keyboard::Return)){
		keyPress=false;
	}
	if(state == preScene && alpha < 500){
		alpha+=5;
		if(alpha <= 250)
			rec.setFillColor(Color(0,0,0,alpha));
		else
			rec.setFillColor(Color(0,0,0,500-alpha));
		if(alpha == 250)
			bgTexture.loadFromFile("Image/title.png");
	}

	if(startButton->getClear()){
        Director::getInstance()->replaceScene(new ChooseMap());
	}

}
void TitleScene::draw(RenderWindow &window){
	window.draw(bg);
	if(state == preScene){
		window.draw(rec);
		window.draw(text);
	}else if(state < preScene){
		window.draw(eye);
		window.draw(text);
	}else{
		startButton->draw(window);
		introButton->draw(window);
	}
}
