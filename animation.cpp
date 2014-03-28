#include "animation.h"

Animation::Animation(std::string path, int tileNumWidth, int tileNumHeight) : currentTexture(0), currentTileX(0), currentTileY(0), tileNum(0), endTileNum(0), tmpElapsedTime(0){
		type = TILE;
		texture.loadFromFile(path);
		tileSizeX = texture.getSize().x / tileNumWidth;
		tileSizeY = texture.getSize().y / tileNumHeight;
		tileSet = new TileSet(texture, tileSizeX, tileSizeY);
		interval = Vector2i(0, 0);
		tileNum = 0;
		endTileNum = (tileNumWidth*tileNumHeight)-1;
        isPlay = true;
}
void Animation::addFrame(std::string path){
        texture.loadFromFile(path);
        textures.push_back(texture);
}

void Animation::setTileRange(sf::Vector2i _intervalPosition, int _numberOfTile){
        interval = _intervalPosition;
        tileNum = (_intervalPosition.x ) + (_intervalPosition.y*(texture.getSize().x/tileSizeX));
        endTileNum = tileNum + _numberOfTile;
}

void Animation::play(sf::Sprite *sprite, sf::Time deltaTime){

        tmpElapsedTime += deltaTime.asSeconds();

        if(type == true){
                sprite->setTexture(texture);
                sprite->setTextureRect(tileSet->getTile(tileNum));

                 if(isPlay){
                        if(tmpElapsedTime > _speed){
                                ++tileNum;
                                tmpElapsedTime = 0;
                        }
                }

				 if (tileNum == endTileNum){
                        tileNum = interval.x + (interval.y)*(texture.getSize().x/tileSizeX);
                }
        }

        else{
                sprite->setTexture(textures[currentTexture]);
                if(isPlay){
                        if(tmpElapsedTime > _speed){
                                ++currentTexture;
                                tmpElapsedTime = 0;
                        }
                }

                if((unsigned int)currentTexture == textures.size())
                        currentTexture=0;
        }
}

void Animation::setSpeed (float speed){
        _speed = speed;
}

void Animation::playAnimation(){
        isPlay = true;
}

void Animation::playAnimationAt(int number){
        tileNum = number;
		currentTexture = number;
        isPlay = true;
}

void Animation::stopAnimation(){
        isPlay = false;
}

void Animation::stopAnimationAt(int num){
        tileNum = num;
		currentTexture = num;
        isPlay = false;
}

void Animation::update(sf::Sprite *sprite){
        play(sprite, deltaTime);
        deltaTime = eTime.restart();
}
int Animation::getFrame(){
	return tileNum;
}