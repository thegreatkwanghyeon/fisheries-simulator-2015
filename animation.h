#ifndef __animation__
#define __animation__

#include "stdafx.h"

#include "tileset.h"

class Animation{
        private:

			enum TYPE{//애니메이션 타입
				IMG,//여러개의 이미지 사용
				TILE//하나의 타일셋 사용
			};

            TileSet *tileSet;//애니메이션에서 사용할 타일셋
            sf::Texture texture;//타일셋 텍스쳐
            sf::Vector2i interval;//타일셋 애니메이션에서 재생할 프레임의 범위
            int numberOfTile;//재생 범위를 정할 때 석택할 타일의 개수
            std::vector<sf::Texture > textures;//여러개의 텍스쳐를 사용할 때 저장할 곳
            int currentTexture;//여러개의 텍스쳐 중 현재 텍스쳐
            int currentTileX;
            int currentTileY;//현재 타일 좌표
            int tileNum;//현재 타일 순서
            int endTileNum;//마지막 타일 순서
            float tmpElapsedTime;//함수 호출 시간 누적
            float _speed;//애니메이션 스피드 (초 단위)
            bool isPlay;//애니메이션의 재생 상태
			bool type;//애니메이션 타입
                
            sf::Clock eTime;//애니메이션 타이머
            sf::Time deltaTime;//함수 호출 시간

            void play(sf::Sprite *sprite, sf::Time deltaTime);//애니메이션 재생  


        public:
				Animation(){ type = IMG; }//여러의 텍스쳐를 사용하는 애니메이션의 생성자
				Animation(std::string path, int tileNumWidth, int tileNumHeight);//타일셋을 사용하는 애니메이션의 생성자
                ~Animation(){delete tileSet;}
                void setSpeed(float speed);//애니메이션 속도 설정 (값이 클수록 느림)
                void addFrame(std::string path);//텍스쳐 추가
                void setTileRange(sf::Vector2i _intervalPosition, int _numberOfTile);//재생할 타일 범위 설정(시작위치, 타일 개수)
                void update(sf::Sprite *sprite);
                void playAnimation();//애니메이션 재생
                void playAnimationAt(int number);//선택한 프레임부터 재생
                void stopAnimation();//애니메이션 정지
                void stopAnimationAt(int num);//선택한 프레임으로 변경 후 정지
                int tileSizeX, tileSizeY;//타일 사이즈
				int getFrame();//현재 프레임을 리턴
};

#endif