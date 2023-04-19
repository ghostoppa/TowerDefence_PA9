#pragma once

#include "playerStats.hpp"
#include <fstream>
#include <iostream>

class Profile
{
public:
	Profile()
	{
		mStats = *new playerStats;
	}
	~Profile()
	{
		mStats.~playerStats();
	}
	//changed to void so it will compile
	void loadProfile();
	void storeProfile();
	playerStats getStats();
	void setStats(playerStats& newStats);

private:
	playerStats mStats;
};