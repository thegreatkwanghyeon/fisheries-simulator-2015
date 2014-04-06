#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include "Well512.h"

using namespace sf;

namespace constants{

	const int INTERNAL_WIDTH = 1280;
	const int INTERNAL_HEIGHT = 800;

	const int LINE_ONE = 450;
	const int LINE_TWO = 600;
	const int LINE_THREE = 750;
	const int LINE_FOUR = 900;

}

#define SPEED_RATIO 0.05

#define M_PI 3.14159265358979323846

using namespace sf;

extern sf::VideoMode desktopMode;

//extern std::wstring MTW(const char* string);
extern Vector2i translate(Vector2i _eye);
extern void setRatio();

extern float abs(float a);

extern Vector2f centerPoint;
extern Vector2f intervalPoint;
extern Vector2f ratio;
extern Vector2f startPoint;

extern int soundVolume;
extern int musicVolume;

extern sf::View view;

extern class MapDB mapDB;
extern class CarDB carDB;

extern FloatRect viewRect;

extern Color conceptColor;

extern int stageNumber;
extern int carColor;
extern int playerCar;

#endif
