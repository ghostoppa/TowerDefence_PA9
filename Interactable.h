#pragma once
#include "StateMachine.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
class Interactable : public sf::RectangleShape
{
public:
	Interactable(sf::Vector2f size, sf::Vector2f positon)
	{
		setPosition(positon);
		setSize(size);
		setFillColor(sf::Color::Red);
		updateable = true;
	}
	
	void update();
	bool button();

	void mouseFollow();

private:
	sf::Vector2i previousMousePos;
	bool updateable;
	

};

