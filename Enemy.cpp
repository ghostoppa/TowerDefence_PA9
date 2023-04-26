#include "Enemy.hpp"
#include <iostream>

float Enemy::rotation() {
	sf::Vector2f target = mPath.getPointAlongPath(this->mSpeed, this->mTime+13), main = this->getPosition();
	float xComp = 0, yComp = 0, angle = 0;

	xComp = target.x - main.x;
	yComp = target.y - main.y;

	angle = atan2(yComp, xComp) * (180.0f / 3.14159f);

	return angle;
}

void Enemy::update()
{
	if (!completed_path)
	{
		
		sf::Vector2f target = mPath.getPointAlongPath(this->mSpeed, this->mTime);
		if(target != sf::Vector2f(-1, -1))
		{
			this->setPosition(target);
			this->setRotation(rotation());
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

bool Enemy::isDefeated()
{
	if (mHealth < 1)
	{
		return true;
	}
	else return false;
}

int Enemy::getCurHealth()
{
	return mHealth;
}

int Enemy::getMaxHealth()
{
	return mMaxHealth;
}

void Enemy::addHealth(int num) {
	mHealth += num;
}

void Enemy::subHealth(int num) {
	mHealth -= num;
}

//void Enemy::render()
//{
//	
//}
