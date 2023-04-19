#pragma once

#include <string>

class playerStats
{
public:
	playerStats()
	{
		name = "null";
		highestRound = 0;
		enemiesKilled = 0;
		livesLost = 0;
	};
	~playerStats() {};

	std::string getName();
	unsigned int getHRound();
	unsigned int getEKilled();
	unsigned int getLLost();
	void setName(std::string newName);
	void setHRound(unsigned int newHRound);
	void setEKilled(unsigned int newEKilled);
	void setLLost(unsigned int newLLost);

	playerStats& operator= (playerStats& rhs);
	
private:
	std::string name;
	unsigned int highestRound;
	unsigned int enemiesKilled;
	unsigned int livesLost;
};