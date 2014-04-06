#include "TileSet.h"

TileSet::TileSet(Texture texture, int tileNumWidth, int tileNumHeight){

	tileSizeX = texture.getSize().x / tileNumWidth;
	tileSizeY = texture.getSize().y / tileNumHeight;

	for (unsigned int i = 0; i <= texture.getSize().y / tileSizeY - 1; i++){
		for (unsigned int j = 0; j <= texture.getSize().x / tileSizeX - 1; j++){
			coords.push_back(Vector2i(j * tileSizeX, i * tileSizeY));
		}
	}
}

IntRect TileSet::getTile(int tileNum){
	
	tileRect.left = coords[tileNum].x;
	tileRect.width = tileSizeX;
	tileRect.top = coords[tileNum].y;
	tileRect.height = tileSizeY;

	return tileRect;
}