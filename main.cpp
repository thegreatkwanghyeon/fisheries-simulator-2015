#include "stdafx.h"
#include "Global.h"
#include "TitleScene.h"
#include "Director.h"

int main(){

	Director *m_pDirector = Director::getInstance();
	m_pDirector->pushScene(new TitleScene());

	view.reset(FloatRect(0, 0, constants::INTERNAL_WIDTH, constants::INTERNAL_HEIGHT));

	sf::RenderWindow window(sf::VideoMode(constants::INTERNAL_WIDTH, constants::INTERNAL_HEIGHT), "Fisheries Simulator 2015", sf::Style::Default);

	while (window.isOpen()){

        	sf::Event event;

        	while (window.pollEvent(event)){

			if (event.type == sf::Event::Closed){
				m_pDirector->freeInstance();
				m_pDirector = NULL;
				window.close();
			}

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			m_pDirector->freeInstance();
			m_pDirector = NULL;
			window.close();
			return 0;
		}

		window.clear();

		window.setView(view);

		m_pDirector->update();
		m_pDirector->draw(window);

        window.display();
        m_pDirector->setNewScene();

	}

	return 0;

}
