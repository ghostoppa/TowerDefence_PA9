#pragma once
#include <sstream>
#include <SFML/Graphics.hpp>
#include <string>


#include "GameClassWip.hpp"
#include "EndState.hpp"
#include "LinearPath.hpp"
#include "Enemy.hpp"
#include "TurretWrapper.hpp"
#include "Round.h"
#include "Map.hpp"


class GameState : public State
{
public:
	GameState(GameDataRef ref);

	void Init();

	void HandleInput();
	void Update();
	void Draw();

	const const int getState()
	{
		return 3;
	}
private:
	GameDataRef data;
	//Tower* testTower;
	sf::Sprite towerArr[4];

	std::vector<Tower> placedTowers;
	void	 doIconMove();
	//void genEnemyForces(std::vector<Enemy>& enemyVector, Map*& map, int& round);

	sf::Sprite menuBackGround;
	bool isGameOver();

	int mMoney;
	int playerLives;
	bool isMoving;
	int round;
	int time;
	int which;
	sf::Clock clock;
	sf::Text* debugLivesText;
	sf::Text* debugMoneyText;
	sf::Text* debugRoundsText;

	Round* cur_round;
	
	Map* testMap;
};