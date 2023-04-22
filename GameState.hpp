#pragma once

#include <sstream>
#include <SFML/Graphics.hpp>
#include "Definitions.hpp"
#include "State.hpp"
#include "GameClassWip.hpp"
#include "LinearPath.hpp"
#include "Enemy.hpp"
#include "Tower.hpp"
#include "Round.h"
#include "Map.hpp"
#include "AssetManager.hpp"

typedef struct GamePlayData
{

};
class   GameState : State
{
public:
	GameState(GameDataRef data) :isMoving(false);

	void Init();

	void HandleInput();
	void Update();
	void Draw();


private:

	GameDataRef data;
	sf::Sprite towerArr[6];
	void	 doIconMove();
	void setSpriteTransparecy(int TowerNumber);
	void runLvl1(sf::RenderWindow& window);
	void genEnemyForces(std::vector<Enemy>& enemyVector, Map*& map, int& round);

	bool isGameOver();

	int mMoney;
	int playerLives;
	bool isMoving;
	int round;
	int time;
	Map* testMap;
};

