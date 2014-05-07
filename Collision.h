#ifndef __collision__
#define __collision__

#include "Dolphin.h"
#include "Hook.h"
#include "Shell.h"

class OrientedBoundingBox{
public:
	OrientedBoundingBox(const Dolphin* dolphin){
		sf::Transform trans = dolphin->getTransform();
		sf::IntRect local = dolphin->getTextureRect();
		Vector2f margin;
		margin.x=local.width/3.0f;
		margin.y=local.height/3.0f;

		Points[0] = trans.transformPoint(margin.x, margin.y);
		Points[1] = trans.transformPoint(local.width-margin.x, margin.y);
		Points[2] = trans.transformPoint(local.width-margin.x, local.height-margin.y);
		Points[3] = trans.transformPoint(margin.x, local.height-margin.y);
	}
	OrientedBoundingBox(const Shell* shell){
		sf::Transform trans = shell->getTransform();
		sf::IntRect local = shell->getTextureRect();
		Vector2f margin;
		margin.x=local.width/3.0f;
		margin.y=local.height/3.0f;

		Points[0] = trans.transformPoint(margin.x, margin.y);
		Points[1] = trans.transformPoint(local.width-margin.x, margin.y);
		Points[2] = trans.transformPoint(local.width-margin.x, local.height-margin.y);
		Points[3] = trans.transformPoint(margin.x, local.height-margin.y);
	}
	OrientedBoundingBox(const Hook* hook){
		sf::Transform trans = hook->getTransform();
		sf::IntRect local = hook->getTextureRect();
		Points[0] = trans.transformPoint(0.f, 0.f);
		Points[1] = trans.transformPoint(local.width, 0.f);
		Points[2] = trans.transformPoint(local.width, local.height);
		Points[3] = trans.transformPoint(0.f, local.height);
	}

	sf::Vector2f Points[4];

	void ProjectOntoAxis(const sf::Vector2f& Axis, float& Min, float& Max){
		Min = (Points[0].x * Axis.x + Points[0].y * Axis.y);
		Max = Min;
		for (int j = 1; j < 4; j++){
			float Projection = (Points[j].x * Axis.x + Points[j].y * Axis.y);

			if (Projection<Min)
				Min = Projection;
			if (Projection>Max)
				Max = Projection;
		}
	}
};

bool BoundingBoxTest(Dolphin* Dolphin1, Hook* Dolphin2);

#endif