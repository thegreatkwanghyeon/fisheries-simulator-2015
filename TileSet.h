#ifndef __TILESET_H__
#define __TILESET_H__

#include "stdafx.h"

using namespace sf;
using namespace std;

class TileSet{
	private:
		vector<sf::Vector2i> coords;
		IntRect tileRect;
		Texture texture;
		int tileSizeX, tileSizeY;

	public:
		TileSet(Texture texture, int tileNumWidth, int tileNumHeight);
		~TileSet(){}
		IntRect getTile(int tileNum);
};

#endif