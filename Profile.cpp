#include "Profile.hpp"

Profile Profile::loadProfile()
{
	std::ifstream infile;
	infile.open("profile1.txt");
	std::cout << "Profile opened." << std::endl;

	std::string name;
	unsigned int highestRound, enemiesKilled, livesLost;
	infile >> name >> highestRound >> enemiesKilled >> livesLost;

	getStats().setName(name); getStats().setHRound(highestRound);
	getStats().setEKilled(enemiesKilled); getStats().setLLost(livesLost);
	
	infile.close();
	std::cout << "Profile loaded and file closed." << std::endl;
}

void Profile::storeProfile()
{
	std::ofstream outfile;
	outfile.open("profile1.txt");
	std::cout << "Profile opened." << std::endl;

	outfile << getStats().getName() << getStats().getHRound() << getStats().getEKilled() << getStats().getLLost();

	outfile.close();
	std::cout << "Profile saved and file closed." << std::endl;
}

playerStats Profile::getStats()
{
	return mStats;
}

void Profile::setStats(playerStats& newStats)
{
	mStats = newStats;
}