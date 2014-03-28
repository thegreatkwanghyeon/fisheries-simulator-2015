#include "button.h"

Button::Button(sf::String _path) : isButtonEnable(true),hotkey(sf::Keyboard::Unknown){
	texture.loadFromFile(_path);
	font.loadFromFile("font/aPinoL.ttf");
	tileset = new TileSet(texture, texture.getSize().x, (texture.getSize().y)/4);
	sprite.setTexture(texture);
	sprite.setTextureRect(tileset->getTile(NormalState));

	//hoverSoundBuffer.loadFromFile("sounds/button/hover.wav");
	//clickSoundBuffer.loadFromFile("sounds/button/click.wav");

	//hoverSound.setBuffer(hoverSoundBuffer);
	//clickSound.setBuffer(clickSoundBuffer);
	
	clickSound.setLoop(false);
	hoverSound.setLoop(false);

	playClickSound = true;
	playHoverSound = true;

}

void Button::setTexture(sf::String _path){
	texture.loadFromFile(_path);
	delete tileset;
	tileset = new TileSet(texture, texture.getSize().x, (texture.getSize().y)/4);
}

void Button::setPosition(float _x, float _y){
	//�̰� �� ��ư �̹����� ��ġ�� ����� ��°� �Ű� ������ 
	position = sf::Vector2f(_x, _y);
	buttonRect = sf::FloatRect(position, sf::Vector2f((float)texture.getSize().x, (float)texture.getSize().y/4));
	sprite.setPosition(_x, _y);
}

void Button::setText(sf::String _name, unsigned int _size){ //_size �� ���� ���ָ� 14�� ����
	buttonName.setFont(font);
	buttonName.setString(_name);
	buttonName.setCharacterSize(_size);
	buttonName.setPosition(position.x + texture.getSize().x / 2 - buttonName.getLocalBounds().width/2,position.y + texture.getSize().y / 8 - buttonName.getLocalBounds().height);

}

bool Button::isMouseOver(sf::Vector2f _mousePosition){
	//buttonRect ���� �ȿ� _mousePosition �� �ִ°�
	return buttonRect.contains(_mousePosition);
}

bool Button::isMouseClicked(){
	return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

void Button::setHotkey(sf::Keyboard::Key _hotkey){
	hotkey = _hotkey;
}

void Button::setClickSound(std::string path){
	clickSoundBuffer.loadFromFile(path);
	clickSound.setBuffer(clickSoundBuffer);
}

void Button::setHoverSound(std::string path){
	hoverSoundBuffer.loadFromFile(path);
	hoverSound.setBuffer(hoverSoundBuffer);
}

void Button::update(sf::Event &event){

	hoverSound.setVolume(soundVolume);
	clickSound.setVolume(soundVolume);

	if(!isButtonEnable){ 
		sprite.setTextureRect(tileset->getTile(DisableState));
	}else if(isMouseOver(mousePosition) && isButtonEnable){
		if(isMouseClicked()){
			if(playClickSound){
				clickSound.stop();
				clickSound.play();
				playClickSound = false;
			}
			sprite.setTextureRect(tileset->getTile(ClickedState));
		}else{
			playClickSound = true;
			if(playHoverSound){
				hoverSound.stop();
				hoverSound.play();
				playHoverSound = false;
			}
			sprite.setTextureRect(tileset->getTile(HoverState));
		}
	}else{
		playHoverSound = true;
		if(sf::Keyboard::isKeyPressed(hotkey)){
			sprite.setTextureRect(tileset->getTile(ClickedState));
		}
		else{
			sprite.setTextureRect(tileset->getTile(NormalState));
		}
	}
	//}else if(sf::Keyboard::isKeyPressed(hotkey)){
	//	sprite.setTextureRect(tileset->getTileSet(ClickedState));
	//}else{
	//	sprite.setTextureRect(tileset->getTileSet(NormalState));
	//}
}

void Button::draw(sf::RenderWindow &window){
	mousePosition = (sf::Vector2f)sf::Mouse::getPosition(window);
	window.draw(sprite);
	window.draw(buttonName);
}


bool Button::checkMouseClick(sf::Event &event){
	/*
		if ���� ���� :

		isButtonEnable �� �ϴ� ������ TRUE ���� �ϰ� (��ư�� Ȱ��ȭ ���ְ�)
			1.isMouseOver(mousePosition) && isMouseClick() �� TRUE �̰ų� (���콺�� �����ų�)
			2.sf::Keyboard::isKeyPressed(hotkey) �� TRUE �϶� (Ű����� ��������)
	*/
	if(isButtonEnable && (((isMouseOver(mousePosition)) && (event.type == sf::Event::MouseButtonPressed)) && (event.mouseButton.button == sf::Mouse::Left) || ((event.type == sf::Event::KeyPressed) && (event.key.code == hotkey)) )){ 
		return true;
	}else{
		return false;
	}
}

void Button::setSprite(sf::String _path){
	texture.loadFromFile(_path);
	delete tileset;
	tileset = new TileSet(texture, texture.getSize().x, (texture.getSize().y)/4);
	sprite.setTexture(texture);
	sprite.setTextureRect(tileset->getTile(NormalState));
}


void Button::enableButton(){
	isButtonEnable = true;
}
void Button::disableButton(){
	isButtonEnable = false;
}
bool Button::getButtonEneble(){
	return isButtonEnable;
}