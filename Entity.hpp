#pragma once
#include <SFML/Graphics.hpp>

//Removed shape inheritance so instead different entities can contain different shapes
class Entity
{
public:
	virtual void update() {};

	//A possible use could be drawing additional elements in an object, like a circle
	//around a tower to show its range
	virtual void render() {};
};


