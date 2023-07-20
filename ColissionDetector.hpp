#pragma once
#include <iostream>
#include <math.h>

#include "Damage.hpp"
#include "Definitions.hpp"
#include "Enemy.hpp"
#include "Entity.hpp"

class ColissionDetector
{
	//might be expanded later
};

bool collisionHandler(int mode, sf::Vector2f* pointOrig, float slope, const sf::CircleShape* circleComp);
int checkSlope(sf::Vector2f* point1, sf::Vector2f* point2, float* slope);
bool checkCollide(const sf::RectangleShape* rectangle, const sf::CircleShape* circle);
