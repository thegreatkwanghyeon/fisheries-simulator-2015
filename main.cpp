#include "stdafx.h"
#include "Global.h"
#include "Director.h"
#include "TitleScene.h"

int main(){

	Director *m_pDirector = Director::getInstance();
	m_pDirector->runWithScene(new TitleScene());

	sf::RenderWindow window(sf::VideoMode(constants::INTERNAL_WIDTH, constants::INTERNAL_HEIGHT), "SFML works!");

	while (window.isOpen()){

        	sf::Event event;

        	while (window.pollEvent(event)){

			if (event.type == sf::Event::Closed){
				m_pDirector->freeInstance();
				m_pDirector = NULL;
				window.close();
				return 0;
			}

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			m_pDirector->freeInstance();
			m_pDirector = NULL;
			window.close();
			return 0;
		}

		window.clear();

		m_pDirector->update();
		m_pDirector->draw(window);

        window.display();

	}

	return 0;

}
