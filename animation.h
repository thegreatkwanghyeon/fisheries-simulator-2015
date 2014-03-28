#ifndef __animation__
#define __animation__

#include "stdafx.h"

#include "tileset.h"

class Animation{
        private:

			enum TYPE{//�ִϸ��̼� Ÿ��
				IMG,//�������� �̹��� ���
				TILE//�ϳ��� Ÿ�ϼ� ���
			};

            TileSet *tileSet;//�ִϸ��̼ǿ��� ����� Ÿ�ϼ�
            sf::Texture texture;//Ÿ�ϼ� �ؽ���
            sf::Vector2i interval;//Ÿ�ϼ� �ִϸ��̼ǿ��� ����� �������� ����
            int numberOfTile;//��� ������ ���� �� ������ Ÿ���� ����
            std::vector<sf::Texture > textures;//�������� �ؽ��ĸ� ����� �� ������ ��
            int currentTexture;//�������� �ؽ��� �� ���� �ؽ���
            int currentTileX;
            int currentTileY;//���� Ÿ�� ��ǥ
            int tileNum;//���� Ÿ�� ����
            int endTileNum;//������ Ÿ�� ����
            float tmpElapsedTime;//�Լ� ȣ�� �ð� ����
            float _speed;//�ִϸ��̼� ���ǵ� (�� ����)
            bool isPlay;//�ִϸ��̼��� ��� ����
			bool type;//�ִϸ��̼� Ÿ��
                
            sf::Clock eTime;//�ִϸ��̼� Ÿ�̸�
            sf::Time deltaTime;//�Լ� ȣ�� �ð�

            void play(sf::Sprite *sprite, sf::Time deltaTime);//�ִϸ��̼� ���  


        public:
				Animation(){ type = IMG; }//������ �ؽ��ĸ� ����ϴ� �ִϸ��̼��� ������
				Animation(std::string path, int tileNumWidth, int tileNumHeight);//Ÿ�ϼ��� ����ϴ� �ִϸ��̼��� ������
                ~Animation(){delete tileSet;}
                void setSpeed(float speed);//�ִϸ��̼� �ӵ� ���� (���� Ŭ���� ����)
                void addFrame(std::string path);//�ؽ��� �߰�
                void setTileRange(sf::Vector2i _intervalPosition, int _numberOfTile);//����� Ÿ�� ���� ����(������ġ, Ÿ�� ����)
                void update(sf::Sprite *sprite);
                void playAnimation();//�ִϸ��̼� ���
                void playAnimationAt(int number);//������ �����Ӻ��� ���
                void stopAnimation();//�ִϸ��̼� ����
                void stopAnimationAt(int num);//������ ���������� ���� �� ����
                int tileSizeX, tileSizeY;//Ÿ�� ������
				int getFrame();//���� �������� ����
};

#endif