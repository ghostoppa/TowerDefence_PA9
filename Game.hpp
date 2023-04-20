#pragma once

#include <iostream>
#include <time.h>

#include "LinearPath.hpp"
#include "Enemy.hpp"
#include "Map.hpp"
#include "AssetManager.hpp"
#include "Definitions.hpp"

class Game
{
public:
	Game() { playerLives = 100; };
	~Game() {};
	void startGame(int level, sf::RenderWindow& window);
private:
	void runLvl1(sf::RenderWindow& window);
	void genEnemyForces(std::vector<Enemy>& enemyVector, Map*& map, int& round);

	bool isGameOver();

	int playerLives;
};