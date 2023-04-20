#include "Round.h"
#include <iostream>

void Round::fetchEnemy(int round_time, std::vector<Enemy>& enemyVector, LinearPath& path, int roundNum)
{
	if (delayTimer == 0 && mEnemyCount > 0)
	{
		//Reset timer
		delayTimer = rand() % maxSpawnDelay;
		int randomSeed = 5 + rand() % 100;
		if (randomSeed < mRedChance)
		{
			if (roundNum >= 10)
			{
				enemyVector.push_back(Enemy(RED_HEALTH, RED_SPEED, path));
			}
			else if (roundNum >= 5)
			{
				enemyVector.push_back(Enemy(YELLOW_HEALTH, YELLOW_SPEED, path));
			}
			else
			{
				enemyVector.push_back(Enemy(GREEN_HEALTH, GREEN_SPEED, path));
			}
		}
		else if(randomSeed < mYellowChance)
		{
			if (roundNum >= 5)
			{
				enemyVector.push_back(Enemy(YELLOW_HEALTH, YELLOW_SPEED, path));
			}
			else
			{
				enemyVector.push_back(Enemy(GREEN_HEALTH, GREEN_SPEED, path));
			}
		}
		else
		{
			enemyVector.push_back(Enemy(GREEN_HEALTH, GREEN_SPEED, path));
		}
		
		--mEnemyCount;
	}
	else
	{
		--delayTimer;
	}
}

bool Round::isDone(std::vector<Enemy>& enemyVector)
{
	return (mEnemyCount == 0 && enemyVector.empty());
}