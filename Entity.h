#pragma once
#include <SFML/Main.hpp>

class Entity
{
public:
	virtual void update();

	virtual void render();
private:
	int x, y;

};

