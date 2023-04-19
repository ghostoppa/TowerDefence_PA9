#include "playerStats.hpp"

playerStats& playerStats::operator= (playerStats& rhs)
{
	name = rhs.name;
	highestRound = rhs.highestRound;
	enemiesKilled = rhs.enemiesKilled;
	livesLost = rhs.livesLost;
}

auto playerStats::getName()
{
	return name;
}
auto playerStats::getHRound()
{
	return highestRound;
}
auto playerStats::getEKilled()
{
	return enemiesKilled;
}
auto playerStats::getLLost()
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