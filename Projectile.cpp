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

void Projectile::getCorners(sf::Vector2f bottomRightCorner, sf::Vector2f topLeftCorner) {
    
}

bool Projectile::collisionDetection(sf::Vector2f bottomRightCorner, sf::Vector2f topLeftCorner) {
    return true;
}

bool Projectile::update(std::vector<Enemy>& enemyVector, std::vector<Projectile>& projectileVector) {
	// frame time updater       //
    tTime++;
    //                          //

    // bullet position update   //
    this->setPosition(this->getPosition().x + (getXComponent(firedAngle) * fireVelocity), this->getPosition().y + (getYComponent(firedAngle) * fireVelocity));
    //                          //
    
    // enemy overlap checker    //
    if (pierce > 0 && chain <= 0) {
        for (int i = 0; i < enemyVector.size(); ++i) {
            if (this->getGlobalBounds().intersects(enemyVector.at(i).getGlobalBounds()) && (aoe > 0 || pierce > 0)) {
                enemyVector.at(i).subHealth(tDamage);
                pierce--;
            }
        }
    }
    //                          //

    //std::cout << "top: " << this->getGlobalBounds().top << " left: " << this->getGlobalBounds().left << std::endl;
    
    if (tTime >= 20 || (pierce <= 0 && aoe <= 0)) {
        return true;
	}

	return false;
}



void Projectile::render()
{
}