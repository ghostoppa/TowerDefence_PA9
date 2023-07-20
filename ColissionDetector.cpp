#include "ColissionDetector.hpp"

bool collisionHandler(int mode, sf::Vector2f* pointOrig, float slope, const sf::CircleShape* circleComp) {
	sf::Vector2f comparePoint;
	float horizontalTranslation = 0, yAdditive = 0, yCompare = 0;
	bool collide = true;
	for (int i = 0 ; i < 8 ; i++) {
		comparePoint.x = circleComp->getPosition().x + (circleComp->getRadius() * cos(((i * 45) * 3.14159f) / 180.0f)); // gets the points on the circle and checks each to see if
		comparePoint.y = circleComp->getPosition().y + (circleComp->getRadius() * sin(((i * 45) * 3.14159f) / 180.0f)); // it is outside of the slope's bounds

		horizontalTranslation = comparePoint.x - pointOrig->x;															// gets the horizontal translation between circle point and slope origin
		yAdditive = horizontalTranslation * slope;																		// gets the rise of the slope at the point on the circle

		switch (mode) {					// this is once again flipped because technically 1 needs to be below and 2 above. Even though from our perspective it is the inverse.
		case 1:
			if ((pointOrig->y + yAdditive) >= comparePoint.y) {
				collide = false;
			}
			else {
				collide = true;			// if even one point is false it has potential to be intersecting, however for each segment, if even one returns all true then it is not colliding
				return collide;
			}
			break;
		case 2:
			if ((pointOrig->y + yAdditive) <= comparePoint.y) {
				collide = false;
			}
			else {
				collide = true;
				return collide;
			}
			break;
		case 3:
			if (pointOrig->x <= comparePoint.x) {
				collide = false;
			}
			else {
				collide = true;
				return collide;
			}
			break;
		case 4:
			if (pointOrig->x >= comparePoint.x) {
				collide = false;
			}
			else {
				collide = true;
				return collide;
			}
			break;
		default:
			std::cout << "unknown ERROR at collision handler slope comparison" << std::endl;
		}
	}
	return collide;
}

int checkSlope(sf::Vector2f* point1, sf::Vector2f* point2, float* slope) {
	int xcomp = 0, ycomp = 0;
	ycomp = (point2->y - point1->y);
	xcomp = (point2->x - point1->x);
	if (xcomp != 0) {
		*slope = ycomp / xcomp;
	}

	if (xcomp == 0) {
		if (ycomp <= 0) {
			return 3;	// on the left since clockwise and this is the return back up
		}
		else if (ycomp >= 0) {
			return 4;	// on the right since clockwise and this is the journey down
		}
	}
	else if (ycomp <= 0 && xcomp >= 0) {		// the Y components are inverse of a standard grid because the game's grid starts at the top left instead of the bottom left
		return 1;		//9 o'clock to 12 o'clock check if above
	}
	else if (ycomp > 0 && xcomp >= 0) {
		return 1;		//12 o'clock to 3 o'clock check if above
	}
	else if (ycomp > 0 && xcomp < 0) {
		return 2;		//3 o'clock to 6 o'clock check if below
	}
	else if (ycomp <= 0 && xcomp < 0) {
		return 2;		//6 o'clock to 9 o'clock check if below
	}
	else { return 0; }
}

bool checkCollide(const sf::RectangleShape* rectangle, const sf::CircleShape* circle){
	bool checkPass = true, breakage = false;
	int i = -1;
	sf::Vector2f prevPoint, curPoint;
	for (int e = 0; e <= rectangle->getPointCount(); e++) {
		prevPoint = curPoint;

		if (e == rectangle->getPointCount()) {
			breakage = true;
			e = 0;
			std::cout << "Break" << std::endl;
		}

		curPoint.x = rectangle->getPosition().x + rectangle->getPoint(e).x * cos((rectangle->getRotation() * 3.141f) / 180) - rectangle->getPoint(e).y * sin((rectangle->getRotation() * 3.141f) / 180);
		curPoint.y = rectangle->getPosition().y + rectangle->getPoint(e).y * cos((rectangle->getRotation() * 3.141f) / 180) + rectangle->getPoint(e).x * sin((rectangle->getRotation() * 3.141f) / 180);

		float slope = 0;
			
		std::cout << "x: " << curPoint.x << " y: " << curPoint.y << std::endl;
		i = checkSlope(&prevPoint, &curPoint, &slope);
		switch (i) {
			case 0:
				std::cout << "Unhandled Collision Exception:: code 2" << std::endl;
				break;

			case 1:
				checkPass = collisionHandler(i, &prevPoint, slope, circle);
					
				break;

			case 2:
				checkPass = collisionHandler(i, &prevPoint, slope, circle);
				break;

			case 3:
				checkPass = collisionHandler(i, &prevPoint, slope, circle);
				break;

			case 4:
				checkPass = collisionHandler(i, &prevPoint, slope, circle);
				break;

			default:
				std::cout << "Anomalous ERROR:: code 4" << std::endl;
				break;
		}
		
		i = -1;
		if (checkPass == false) {
			break;
		}
		if (breakage == true) {
			break;
		}
	}
	return checkPass;
}
