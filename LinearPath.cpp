#include "LinearPath.hpp"
#include <math.h>
#include <iostream>

void LinearPath::addPoint(sf::Vector2f loc)
{
	//if point collection has an element
	if (pointCollection.size() > 0)
	{
		float pt_dist = sqrt(
			pow(loc.x - pointCollection.at(pointCollection.size() - 1).x, 2) +
			pow(loc.y - pointCollection.at(pointCollection.size() - 1).y, 2)
		);

		//Store the distances between each point in a vector so we don't have to compute the distance
		//Every time we need it (sqrt is heavy)
		pathDistances.push_back(pt_dist);
		//add to total distance
		total_distance += pt_dist;
	}
	//increment point count and add point to point collection
	++point_count;
	pointCollection.push_back(loc);
}

sf::Vector2f LinearPath::getPointAlongPath(float speed, float t)
{
	sf::Vector2f cur_point, next_point;
	//Get distance at time t along path at current speed
	float distance = fmod(speed * t, total_distance);
	float seg_length = 0;
	bool found_point = false;

	//if point collection has more than one element
	if (pointCollection.size() > 0 && speed * t < total_distance)
	{
		//determine which points we are interpolating between
		//take this by repeatedly adding the distances between each point
		//until the total is greater than the already elapsed distance
		//so then we set point A to the previous point and point B to the found point
		
		int i = 1;
		for(; i < pointCollection.size() && !found_point; ++i)
		{
			seg_length += pathDistances[i - 1];
			if (seg_length > distance)
			{
				//found the points surrounding the current position
				next_point = pointCollection[i];
				cur_point = pointCollection[i - 1];
				
				found_point = true;
			}
		}
		//float point_dist = sqrt(pow(next_point.x - cur_point.x, 2) + pow(next_point.y - cur_point.y, 2));
		float point_dist = pathDistances[i - 2];

		float new_t = (distance - (seg_length - point_dist)) / point_dist;
		return lerp(cur_point, next_point, new_t);

	}
	else
	{
		// T is greater than path
		return sf::Vector2f(-1, -1);
	}

}

sf::Vector2f LinearPath::lerp(sf::Vector2f start, sf::Vector2f end, float t)
{
	float x = start.x + (end.x - start.x) * t;
	float y = start.y + (end.y - start.y) * t;

	return sf::Vector2f(x, y);
}
