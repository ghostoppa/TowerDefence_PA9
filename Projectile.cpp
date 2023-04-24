#include "Projectile.h"

float Projectile::getXComponent(float angle) {
    float xComp = 0, radian = 3.14159 / 180;
    if (angle <= 90) {
        xComp = (cos(angle * radian));
    }
    else if (angle <= 180) {
        angle = 180 - angle;
        xComp = -(cos(angle * radian));
    }
    else if (angle <= 270) {
        angle -= 180;
        xComp = -(cos(angle * radian));
    }
    else {
        angle = 360 - angle;
        xComp = (cos(angle * radian));
    }
    return xComp;
}
float Projectile::getYComponent(float angle) {
    float yComp = 0, radian = 3.14159 / 180;
    if (angle <= 90) {
        yComp = (sin(angle * radian));
    }
    else if (angle <= 180) {
        angle = 180 - angle;
        yComp = (sin(angle * radian));
    }
    else if (angle <= 270) {
        angle -= 180;
        yComp = -(sin(angle * radian));
    }
    else {
        angle = 360 - angle;
        yComp = -(sin(angle * radian));
    }
    return yComp;
}

bool Projectile::update(std::vector<Enemy>& enemyVector, std::vector<Projectile>& projectileVector) {
	tTime++;
    this->setPosition(this->getPosition().x + (getXComponent(firedAngle) * fireVelocity), this->getPosition().y + (getYComponent(firedAngle) * fireVelocity));

	if (tTime >= 20) {
		return true;
	}

	return false;
}



void Projectile::render()
{
}