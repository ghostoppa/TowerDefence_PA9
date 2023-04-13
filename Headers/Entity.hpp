#pragma once
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

class Entity : public sf::Shape;
{
public:
	virtual void update();

	virtual void render();

	virtual Vector
private:
	sf::Vector2f positon;
	
	

};

