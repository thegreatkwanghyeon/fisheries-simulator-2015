#include "Global.h"
/*
std::wstring MTW( const char* string){
	int stringSize = MultiByteToWideChar(CP_UTF8, 0, string, strlen(string), NULL, 0);
	std::vector<wchar_t> tmpString;
	std::wstring returnString;

	tmpString.resize(stringSize);
	MultiByteToWideChar(CP_UTF8, 0, string,strlen(string), &tmpString[0], stringSize);

	for(unsigned int i=0;i<tmpString.size();i++){
		returnString.push_back(tmpString[i]);
	}

	return returnString;
}
*/
Vector2i translate(Vector2i _eye){
	Vector2i eyePoint;
	float temp;

	temp=(_eye.x-startPoint.x)*ratio.x;
	eyePoint.x=(int)temp;
	temp=(_eye.y-startPoint.y)*ratio.y;
	eyePoint.y=(int)temp;


	return eyePoint;
}
void setRatio(){
	centerPoint.x=960;
	centerPoint.y=600;

	intervalPoint.x=860;
	intervalPoint.y=500;

	ratio.x=100/(centerPoint.x-intervalPoint.x);
	ratio.y=100/(centerPoint.y-intervalPoint.y);

	startPoint.x=centerPoint.x-((constants::INTERNAL_WIDTH/2)*ratio.x);
	startPoint.y=centerPoint.y-((constants::INTERNAL_HEIGHT/2)*ratio.y);
}

float abs(float a){
    if(a < 0){
        a *= -1;
    }
    return a;
}

Vector2f centerPoint;
Vector2f intervalPoint;
Vector2f ratio;
Vector2f startPoint;

sf::VideoMode desktopMode;

sf::View view;

int musicVolume = 50;
int soundVolume = 50;

MapDB mapDB;
CarDB carDB;

FloatRect viewRect;

Color conceptColor = Color(0, 237, 250, 255);

int stageNumber = 0;
int carColor = 0;
int playerCar = 0;

