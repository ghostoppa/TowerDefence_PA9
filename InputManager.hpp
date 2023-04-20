#pragma once
#include "SFML/Graphics.hpp"

class InputManager
{
public:
	InputManager() {}
	~InputManager() {}

	bool IsSpriteClicked(sf::Sprite& spriteRef, sf::Mouse::Button button,
		sf::RenderWindow& window);

	sf::Vector2i getMousePosition(sf::RenderWindow& w);
};