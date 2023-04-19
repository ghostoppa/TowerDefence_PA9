#include "Enemy.hpp"
#include <iostream>
void Enemy::update()
{
	if (!completed_path)
	{
		
		sf::Vector2f target = mPath.getPointAlongPath(this->mSpeed, this->mTime);
		if(target != sf::Vector2f(-1, -1))
		{
			this->setPosition(target);
		}
		else
		{
			completed_path = true;
		}
		mTime += 1;
	}
	else
	{
		//code that runs when you finish the path
		//Take away from player health?
	}
}


void Enemy::render()
{
	
}
