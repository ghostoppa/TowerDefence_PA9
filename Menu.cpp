#include "Menu.hpp"


void Menu::setTexture(int object,const  sf::Texture* objectTexture)
{
	this->menuShape[0].setTexture(objectTexture, true);
}

sf::RectangleShape &Menu::getMenuShape(int i)
{
	return this->menuShape[i];
}
