#include "Interactable.h"
#include <iostream>

void Interactable::update(sf::Window& mouseWindow)
{
	//if mouse is outside button
	if (!dragging && !(this->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(mouseWindow))))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			mouseDownOutside = true;
		}
		else
		{
			mouseDownOutside = false;
		}
	}
	//Check if mouse is inside button
	if (!mouseDownOutside && (dragging || this->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(mouseWindow))))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			mouseFollow(mouseWindow);
			dragging = true;
		}
		else if (dragging)
		{
			dragging = false;
		}
	}
	
}

bool Interactable::button(sf::Window& mouseWindow)
{
//	if (sf::Mouse::Button::Left)
	//{
		sf::Vector2i mousPos(sf::Mouse::getPosition(mouseWindow));
		this->previousMousePos = mousPos;
		return true;
}

void Interactable::mouseFollow(sf::Window& mouseWindow)
{
	if (button(mouseWindow)&&this->updateable)
	{
		//sf::Vector2i mousPos(sf::Mouse::getPosition());
		//int deltaX = mousPos.x - this->previousMousePos.x,
		//	deltaY = mousPos.y - this->previousMousePos.y;
		//move(sf::Vector2f(deltaX, deltaY));

		//Localize mouse coordinates to window
		sf::Vector2i mousePos(sf::Mouse::getPosition(mouseWindow));
		//Set center of object to mouse
		setPosition((sf::Vector2f)mousePos);
	}
}