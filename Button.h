#ifndef __Button__
#define __Button__

#include "stdafx.h"
#include "tileset.h"
#include "global.h"

class Button {
	private:

		enum State{
			NormalState, //일반적인 상태
			HoverState,  //마우스 올렸을때
			ClickedState,//클릭되었을때 
			DisableState,//클릭할수 없는 상태일때 
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
		void setText(sf::String _name, unsigned int _size,  sf::Vector2f _position);
		void enableButton();
		void disableButton();
		bool checkMouseClick();
		void setHotkey(sf::Keyboard::Key _hotkey);
		void setSprite(sf::String _path);
		void setOrigin(float x, float y);
		void setTextColor(sf::Color _color);

		bool getButtonEneble();
		void setTexture(sf::String _path);

};
#endif