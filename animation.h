#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "stdafx.h"
#include "TileSet.h"

class Animation{
        private:

			enum TYPE{
				IMG,
				TILE
			};

            TileSet *tileSet;
            sf::Texture texture;
            sf::Vector2i interval;
            int numberOfTile;
            std::vector<sf::Texture > textures;
            int currentTexture;
            int currentTileX;
            int currentTileY;
            int tileNum;
            int endTileNum;
            float tmpElapsedTime;
            float _speed;
            bool isPlay;
			bool type;
                
            int tileSizeX, tileSizeY;

            sf::Clock eTime;
            sf::Time deltaTime;

            void play(sf::Sprite *sprite, sf::Time deltaTime);


        public:

				Animation(){ type = IMG; }
				Animation(std::string path, int tileNumWidth, int tileNumHeight);
                ~Animation(){delete tileSet;}
                void setSpeed(float speed);
                void addFrame(std::string path);
                void setTileRange(sf::Vector2i _intervalPosition, int _numberOfTile);
                void update(sf::Sprite *sprite);
                void playAnimation();
                void playAnimationAt(int number);
                void stopAnimation();
                void stopAnimationAt(int num);
				int getFrame();
};

#endif