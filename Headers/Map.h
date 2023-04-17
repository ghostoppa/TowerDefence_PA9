#pragma once
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include "LinearPath.h"
class Map : public sf::Sprite
{
public:
	Map(std::string texturePath, std::string pathPath, std::string hitboxPath)
	{
		tex = new sf::Texture;
		tex->loadFromFile(texturePath);
		setTexture(*tex);

		LoadPathFromFile(pathPath);
		LoadHitBoxesFromFile(hitboxPath);
	};

	void LoadPathFromFile(std::string path);

	void LoadHitBoxesFromFile(std::string path);

	LinearPath* getPath() { return &enemyPath; };

	std::vector<sf::RectangleShape>* getHitboxes() { return &hitboxes; };
private:
	sf::Texture* tex;

	//Include list of hitboxes for areas where towers can be placed?
	//These could probably be predefined by finding the coordinates in an image editor
	std::vector<sf::RectangleShape> hitboxes;

	LinearPath enemyPath;
};

