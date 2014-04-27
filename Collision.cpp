#include "Collision.h"

bool BoundingBoxTest(Dolphin* Dolphin1, Hook* hook){
	OrientedBoundingBox OBB1(Dolphin1);
	OrientedBoundingBox OBB2(hook);

	sf::Vector2f Axes[4] = {
		sf::Vector2f(OBB1.Points[1].x - OBB1.Points[0].x,
		OBB1.Points[1].y - OBB1.Points[0].y),
		sf::Vector2f(OBB1.Points[1].x - OBB1.Points[2].x,
		OBB1.Points[1].y - OBB1.Points[2].y),
		sf::Vector2f(OBB2.Points[0].x - OBB2.Points[3].x,
		OBB2.Points[0].y - OBB2.Points[3].y),
		sf::Vector2f(OBB2.Points[0].x - OBB2.Points[1].x,
		OBB2.Points[0].y - OBB2.Points[1].y)
	};

	for (int i = 0; i < 4; i++){
		float MinOBB1, MaxOBB1, MinOBB2, MaxOBB2;

		OBB1.ProjectOntoAxis(Axes[i], MinOBB1, MaxOBB1);
		OBB2.ProjectOntoAxis(Axes[i], MinOBB2, MaxOBB2);

		if (!((MinOBB2 <= MaxOBB1) && (MaxOBB2 >= MinOBB1)))
			return false;
	}

	return true;
}