#pragma once
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
//LinearPath will be a collection of points in a std::vector that enemies will follow

class LinearPath
{
public:
	LinearPath() { point_count = 0, total_distance = 0; };

	void addPoint(sf::Vector2f loc); //add point to path (increase point_count too)

	//Used to progress through points in path at a constant speed
	sf::Vector2f getPointAlongPath(float speed, float t);

private:
	int point_count;
	float total_distance;

	std::vector<sf::Vector2f> pointCollection;

	//Return a point between two points at point t
	sf::Vector2f lerp(sf::Vector2f start, sf::Vector2f end, float t);


};

