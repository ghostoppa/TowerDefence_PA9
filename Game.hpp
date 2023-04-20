#pragma once

#include <iostream>
#include <time.h>

#include "LinearPath.hpp"
#include "Enemy.hpp"
#include "Map.hpp"
#include "AssetManager.hpp"
#include "Definitions.hpp"
#include "Interactable.h"

class Game
{
public:
	Game() { playerLives = 100; mMoney = 250; };
	~Game() {};
	void startGame(int level, sf::RenderWindow& window);

private:
	void runLvl1(sf::RenderWindow& window);

	bool isGameOver();

	int mMoney;
	int playerLives;
};