#pragma once
#include <vector>
#include <time.h>
#include "Enemy.hpp"
#include "LinearPath.hpp"
#include "Definitions.hpp"
#include "AssetManager.hpp"

class Round
{
public:
	//# of enemies, chances of spawning yellow or red, max delay in between spawning
	//enemies. Chances should ideally be in percentages out of 100. set to 0 to prevent them from
	//spawning at all
	Round(int enemycount, float c_yellow, float c_red, int maxDelay) :
		mEnemyCount(enemycount), mYellowChance(c_yellow),
		mRedChance(c_red), maxSpawnDelay(maxDelay)
	{};

	void fetchEnemy(AssetManager& enemies, int round_time, std::vector<Enemy>& enemyVector, LinearPath& path, int roundNum);

	bool isDone(std::vector<Enemy>& enemyVector);

private:
	//Number of enemies summoned during the round
	int mEnemyCount;
	//Chance of summoning each type of enemy
	float mYellowChance, mRedChance;
	//Longest time to wait before summoning a new enemy
	int maxSpawnDelay;

	int enemiesSummoned = 0;
	int delayTimer = 0;
	int lastEnemyTime = 0;
};

