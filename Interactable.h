#pragma once
#include "StateMachine.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
class Interactable : public sf::RectangleShape
{
public:
	Interactable(sf::Vector2f size, sf::Vector2f position)
	{
		setPosition(position);
		setSize(size);
		setFillColor(sf::Color::Red);
		updateable = true;
		dragging = false;
		mouseDownOutside = false;
	}
	
	void update(sf::Window& mouseWindow);
	bool button(sf::Window& mouseWindow);

	void mouseFollow(sf::Window& mouseWindow);

private:
	sf::Vector2i previousMousePos;
	bool updateable;
	bool dragging;
	bool mouseDownOutside;

};

