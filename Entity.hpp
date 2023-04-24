#pragma once
#include <SFML/Graphics.hpp>

//Removed shape inheritance so instead different entities can contain different shapes
class Entity
{
public:
	virtual void update();

	//Remove? window.draw(object) works well enough
	//A possible use could be drawing additional elements in an object, like a circle
	//around a tower to show its range
	virtual void render();

	//Also removed get/setposition because all the shape classes already have this
private:

};


