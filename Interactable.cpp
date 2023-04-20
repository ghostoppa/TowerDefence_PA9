#include "Interactable.h"

#include <iostream>
void Interactable::update()
{
	mouseFollow();
}

bool Interactable::button()
{
//	if (sf::Mouse::Button::Left)
	//{
		sf::Vector2i mousPos(sf::Mouse::getPosition());
		this->previousMousePos = mousPos;
		return true;
	}

		void Interactable::mouseFollow()
{
	//if (button()&&this->updateable)
	{
		sf::Vector2i mousPos(sf::Mouse::getPosition());
		int deltaX = mousPos.x - this->previousMousePos.x,
			deltaY = mousPos.y - this->previousMousePos.y;
		std::cout << "Mouse Pos X :" << mousPos.x<<std::endl;
		std::cout << "Mouse Pos Y :" << mousPos.y << std::endl;;
		setPosition(mousPos.x, mousPos.y);
		}
}