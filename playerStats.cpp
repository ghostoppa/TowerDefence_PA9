#include "playerStats.hpp"

playerStats& playerStats::operator= (playerStats& rhs)
{
	name = rhs.name;
	highestRound = rhs.highestRound;
	enemiesKilled = rhs.enemiesKilled;
	livesLost = rhs.livesLost;
	return rhs;
}

std::string playerStats::getName()
{
	return name;
}
unsigned int playerStats::getHRound()
{
	return highestRound;
}
unsigned int playerStats::getEKilled()
{
	return enemiesKilled;
}
unsigned int playerStats::getLLost()
{
	return livesLost;
}
void playerStats::setName(std::string newName)
{
	name = newName;
}
void playerStats::setHRound(unsigned int newHRound)
{
	highestRound = newHRound;
}
void playerStats::setEKilled(unsigned int newEKilled)
{
	enemiesKilled = newEKilled;
}
void playerStats::setLLost(unsigned int newLLost)
{
	livesLost = newLLost;
}