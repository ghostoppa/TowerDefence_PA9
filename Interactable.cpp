#include "Interactable.h"


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
	if (button()&&this->updateable)
	{
		sf::Vector2i mousPos(sf::Mouse::getPosition());
		int deltaX = mousPos.x - this->previousMousePos.x,
			deltaY = mousPos.y - this->previousMousePos.y;
		move(sf::Vector2f(deltaX, deltaY));
	}
}