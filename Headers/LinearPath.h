#pragma once
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
//LinearPath will be a collection of points in a std::vector that enemies will follow

class LinearPath
{
public:
	LinearPath() { point_count = 0; };

	void addPoint(sf::Vector2f loc); //add point to path (increase point_count too)

	sf::Vector2f getPointAlongPath(float t); //Return a point along the path at time t, ideally t = 0 should be where it starts and t = 100 is where it ends

private:
	int point_count;
	std::vector<sf::Vector2f> pointCollection;
};

