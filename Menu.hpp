#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class Menu
{
public:
	Menu(float width, float hight);
	~Menu();

private:
	int selectedItemIndex;
	sf::Font MenuFont
	void draw(RenderWindow& Window)
};

