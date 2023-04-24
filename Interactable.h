#pragma once
#include "StateMachine.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
class Interactable : public sf::Sprite
{
public:
	Interactable()
	{
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

