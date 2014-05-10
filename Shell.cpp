#include "Shell.h"
#include <stdlib.h>
#include <time.h>

Shell::Shell(){
	texOpenedShell.loadFromFile("img/shellOpened.png");
	texClosedShell.loadFromFile("img/shellClosed.png");
	spShell.setTexture(texClosedShell);
	spShell.setOrigin(spShell.getLocalBounds().width/2,0);
	spShell.setPosition(400.0f,600.0f-spShell.getLocalBounds().height+5.0f);

	chkOpen=false;
	isDead=false;
}

Shell::~Shell(){

}

void Shell::update(){
	if(isDead){
		spShell.setTexture(texClosedShell);
		return;
	}
	if(chkOpen){
		if(clock.getElapsedTime().asSeconds() >= 3.0){
			chkOpen=false;
			spShell.setTexture(texClosedShell);
			everyClock.restart();
		}
		return;
	}else{
		srand(time(NULL));
		if(everyClock.getElapsedTime().asSeconds()*timeRatio >= 1.0){//1ÃÊ°¡ ‰ç´Ù.
			int random = rand()%5;
			printf("[%d]\n",random);
			if(random == 0){//5%
				chkOpen=true;
				clock.restart();
				spShell.setTexture(texOpenedShell);
			}
			everyClock.restart();
		}
	}
}

void Shell::draw(RenderWindow &window){
	window.draw(spShell);
}
void Shell::setPosition(Vector2f _pos){
	spShell.setPosition(_pos);
}
void Shell::setDead(bool _dead){
	isDead=_dead;
}
bool Shell::getDead(){
	return isDead;
}