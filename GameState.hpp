#pragma once
#include "Interactable.h"
#include <sstream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Definitions.hpp"
#include "State.hpp"
#include "GameClassWip.hpp"

#include "LinearPath.hpp"
#include "Enemy.hpp"
#include "TurretWrapper.hpp"
#include "Round.h"
#include "Map.hpp"

class   GameState : public State
{
public:
	GameState(GameDataRef ref);

	void Init();

	void HandleInput();
	void Update();
	void Draw();


private:

	GameDataRef data;
	//Tower* testTower;
	sf::Sprite towerArr[4];

	std::vector<Tower> placedTowers;
	void	 doIconMove();
	void setSpriteTransparecy(int TowerNumber);
	void runLvl1(sf::RenderWindow window);
	//void genEnemyForces(std::vector<Enemy>& enemyVector, Map*& map, int& round);

	sf::Sprite menuBackGround;
	bool isGameOver();

	int mMoney;
	int playerLives;
	bool isMoving;
	int round;
	int time;
	int which;

	sf::Text* debugLivesText;
	sf::Text* debugMoneyText;
	sf::Text* debugRoundsText;
	sf::Text* shopText;
	sf::Text* t1Title;
	sf::Text* t2Title;
	sf::Text* t3Title;
	sf::Text* t4Title;

	Round* cur_round;
	
	Map* testMap;
};

