#pragma once
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

//Inherit from sf::RectangleShape rather than sf::Shape and instead render a texture inside containing the desired shape?
//Instead however the bounding box will always be a rectangle, but that shouldn't be much of an issue
class Entity : public sf::RectangleShape
{
public:
	virtual void update();

	virtual void render();

	virtual sf::Vector2f getPosition();
private:
	sf::Vector2f position;
};


