#ifndef __Button__
#define __Button__

#include "stdafx.h"
#include "tileset.h"
#include "SFML/Audio.hpp"
#include "global.h"

class Button {
	private:

		enum State{
			NormalState, //�Ϲ����� ����
			HoverState,  //���콺 �÷�����
			ClickedState,//Ŭ���Ǿ����� 
			DisableState,//Ŭ���Ҽ� ���� �����϶� 
		};

		sf::Sprite    sprite;
		//sf::Sprite    sprites[4];
		sf::Texture   texture;
		sf::Vector2f  position;
		sf::Vector2f  mousePosition;
		sf::FloatRect   buttonRect;
		sf::Font      font;
		sf::Text      buttonName;

		TileSet *tileset;
		sf::Keyboard::Key hotkey;

		bool isButtonEnable;

		bool isMouseOver (sf::Vector2f _mousePosition);
		bool isMouseClicked ();


	public:
		Button(sf::String _path);
		~Button(){delete tileset;}
		void update();
		void draw(sf::RenderWindow &window);
		void setPosition(float _x, float _y);
		void setText (sf::String _name, unsigned int _size = 14);
		void enableButton();
		void disableButton();
		bool checkMouseClick();
		void setHotkey(sf::Keyboard::Key _hotkey);
		void setSprite(sf::String _path);

		bool getButtonEneble();
		void setTexture(sf::String _path);

};
#endif