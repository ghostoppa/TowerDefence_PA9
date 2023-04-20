#include "Interactable.h"
#include <SFML/Window.hpp>
#include <iostream>
void Interactable::update()
{
	mouseFollow();
}

bool Interactable::button()
{
	if (sf::Mouse::Button::Left)
	{
		sf::IntRect tempIRec(this->get)
	}
}
		void Interactable::mouseFollow()
{
	if (button()&&this->updateable)
	{
		sf::Vector2i mousPos(sf::Mouse::getPosition());
		int deltaX = mousPos.x,	deltaY = mousPos.y;
		std::cout << "Mouse Pos X :" << mousPos.x << std::endl;
		std::cout << "Mouse Pos Y :" << mousPos.y << std::endl;;
		setPosition((mousPos.x)*(640.0/1920), (mousPos.y)*(480.0/1080));
		}
}