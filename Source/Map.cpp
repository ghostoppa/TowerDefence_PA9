#include "../Headers/Map.h"
#include <iostream>
#include <fstream>

void Map::LoadPathFromFile(std::string path)
{
	std::cout << "Loading map path data..." << std::endl;
	std::ifstream infile;
	infile.open(path);
	float x, y;
	while (infile)
	{
		infile >> x;
		infile >> y;
		std::cout << "x : " << x << ", y: " << y << std::endl;
		this->enemyPath.addPoint(sf::Vector2f(x, y));
	}
	std::cout << "Loaded path!" << std::endl;
}

void Map::LoadHitBoxesFromFile(std::string path)
{
	std::cout << "Loading map hitbox data..." << std::endl;
	std::ifstream infile;
	infile.open(path);
	float x, y, w, h;
	while (infile)
	{
		infile >> x;
		infile >> y;
		infile >> w;
		infile >> h;
		sf::RectangleShape temp;
		temp.setPosition(sf::Vector2f(x, y));
		temp.setSize(sf::Vector2f(w, h));
		this->hitboxes.push_back(temp);
	}
	std::cout << "Loaded path!" << std::endl;
}
