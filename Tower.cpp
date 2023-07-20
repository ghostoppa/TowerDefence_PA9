#include "Tower.hpp"

float Tower::targetingFeed(const sf::Vector2f& pointMain, const sf::Vector2f& pointTarget) {
    float xComp = 0, yComp = 0, width = 0, height = 0, distance = 0;

    xComp = pointMain.x - pointTarget.x;
    yComp = pointMain.y - pointTarget.y;
    width = powf(xComp, 2.0f);
    height = powf(yComp, 2.0f);
    distance = sqrtf(width + height);

    return distance;
}

float Tower::targetingFeed(const sf::Vector2f& pointMain, const sf::Vector2f& pointTarget, float* angle) {
    float xComp = 0, yComp = 0, width = 0, height = 0, distance = 0;

    xComp = pointTarget.x - pointMain.x;
    yComp = pointTarget.y - pointMain.y;
    width = powf(xComp, 2.0f);
    height = powf(yComp, 2.0f);
    distance = sqrtf(width + height);

    *angle = atan2(yComp, xComp) * (180.0f / 3.14159f);

    return distance;
}

Enemy* Tower::targetClosest(std::vector<Enemy>& enemyVector) {
    Enemy* pEnemy = nullptr, * cEnemy = nullptr;
    float pDist = fireRange, cDist = fireRange;
    for (int i = 0; i < enemyVector.size(); ++i) {
        if (cDist > targetingFeed(this->getPosition(), enemyVector.at(i).getPosition())) {
            cEnemy = &enemyVector.at(i);
            cDist = targetingFeed(this->getPosition(), enemyVector.at(i).getPosition());
        }
    }
    previousDistanceToTarget = cDist;
    return cEnemy;
}

Enemy* Tower::targetFirst(std::vector<Enemy>& enemyVector) {
    Enemy* cEnemy = nullptr;
    float cDist = fireRange;
    for (int i = 0; i < enemyVector.size(); ++i) {
        if (fireRange > targetingFeed(this->getPosition(), enemyVector.at(i).getPosition())) {
            cEnemy = &enemyVector.at(i);
            cDist = targetingFeed(this->getPosition(), enemyVector.at(i).getPosition());
            break;
        }
    }
    return cEnemy;
}

Enemy* Tower::targetLast(std::vector<Enemy>& enemyVector) {
    Enemy* cEnemy = nullptr;
    float cDist = fireRange;
    for (int i = 0; i < enemyVector.size(); ++i) {
        if (fireRange > targetingFeed(this->getPosition(), enemyVector.at(enemyVector.size() - 1 - i).getPosition())) {
            cEnemy = &enemyVector.at(enemyVector.size() - 1 - i);
            cDist = targetingFeed(this->getPosition(), enemyVector.at(enemyVector.size() - 1 - i).getPosition());
            break;
        }
    }
    return cEnemy;
}

Enemy* Tower::targetLock(std::vector<Enemy>& enemyVector) {
    Enemy* pEnemy = nullptr, * cEnemy = nullptr;
    float pDist = fireRange, cDist = fireRange;
    if (target == nullptr) {
        for (int i = 0; i < enemyVector.size(); ++i) {
            if (fireRange > targetingFeed(this->getPosition(), enemyVector.at(enemyVector.size() - 1 - i).getPosition())) {
                cEnemy = &enemyVector.at(enemyVector.size() - 1 - i);
                cDist = targetingFeed(this->getPosition(), enemyVector.at(enemyVector.size() - 1 - i).getPosition());
                break;
            }
        }
    }
    else if (target != nullptr && fireRange < targetingFeed(this->getPosition(), target->getPosition())) {
        for (int i = 0; i < enemyVector.size(); ++i) {
            if (fireRange > targetingFeed(this->getPosition(), enemyVector.at(enemyVector.size() - 1 - i).getPosition())) {
                cEnemy = &enemyVector.at(enemyVector.size() - 1 - i);
                cDist = targetingFeed(this->getPosition(), enemyVector.at(enemyVector.size() - 1 - i).getPosition());
                break;
            }
        }
    }
    else {
        cEnemy = target;
    }
    return cEnemy;
}

Enemy* Tower::targetStrong(std::vector<Enemy>& enemyVector) {
    Enemy* cEnemy = nullptr;
    float cDist = fireRange;
    int highestHealth = 0;
    if (target != nullptr) {
        highestHealth = target->getMaxHealth();
    }

    if (target == nullptr) {
        for (int i = 0; i < enemyVector.size(); ++i) {
            if (fireRange > targetingFeed(this->getPosition(), enemyVector.at(i).getPosition()) && highestHealth < enemyVector.at(i).getMaxHealth()) {
                cEnemy = &enemyVector.at(i);
                cDist = targetingFeed(this->getPosition(), enemyVector.at(enemyVector.size() - 1 - i).getPosition());
                break;
            }
        }
    }
    else if (target != nullptr && target->getMaxHealth() < RED_HEALTH) {
        for (int i = 0; i < enemyVector.size(); ++i) {
            if (fireRange > targetingFeed(this->getPosition(), enemyVector.at(i).getPosition()) && highestHealth < enemyVector.at(i).getMaxHealth()) {
                cEnemy = &enemyVector.at(i);
                cDist = targetingFeed(this->getPosition(), enemyVector.at(enemyVector.size() - 1 - i).getPosition());
                break;
            }
        }
    }
    else {
        cEnemy = target;
    }
    return cEnemy;
}

Enemy* Tower::getTarget(std::vector<Enemy>& enemyVector, int priorityType) {
    Enemy* pEnemy = nullptr, * cEnemy = nullptr;
    float pDist = fireRange, cDist = fireRange;
    switch (priorityType) {
    case 0:
        //first
        cEnemy = targetFirst(enemyVector);
        break;


    case 1:
        //closest
        cEnemy = targetClosest(enemyVector);
        break;


    case 2:
        //last
        cEnemy = targetLast(enemyVector);
        break;

    case 3:
        //lock
        cEnemy = targetLock(enemyVector);
        break;

    case 4:
        //strong
        cEnemy = targetStrong(enemyVector);
        break;

    default:
        //acquire and lock
        if (target != nullptr) {
            for (int i = 0; i < enemyVector.size(); ++i) {
                if (cDist > targetingFeed(this->getPosition(), enemyVector.at(i).getPosition())) {
                    cEnemy = &enemyVector.at(i);
                    cDist = targetingFeed(this->getPosition(), enemyVector.at(i).getPosition());
                }
            }
        }
        break;
    }

    return cEnemy;
}

void Tower::fireProjectile(std::vector<Projectile>& projectileVector) {
    projectileVector.push_back(Projectile(this, *projectile, this->getPosition(), this->getRotation(), mDamage, projectileChainRange, projectileVelocity, projectileAOE, projectileChain, projectilePierce));
}

void Tower::setPos(const sf::Vector2f& position) {
    this->setPosition(position);
    return;
}

int Tower::getKills() {
    return mKills;
}
void Tower::addKill() {
    mKills++;
    return;
}

int Tower::getPrice() {
    return this->mPrice;
}

float Tower::getRange() {
    return this->fireRange;
}

sf::CircleShape* Tower::getRangeCircle() {
    return rangeCircle;
}

void Tower::showRadius(int valid) {
    if (1 == valid) {
        rangeCircle->setFillColor(sf::Color(100, 100, 100, 100));
    }
    else {
        rangeCircle->setFillColor(sf::Color(100, 100, 100, 0));
    }
    return;
}
void Tower::showRadius(float range) {
    rangeCircle->setFillColor(sf::Color(100, 0, 0, 100));
    rangeCircle->setRadius(range);
    return;
}

void Tower::update(std::vector<Enemy>& enemyVector, std::vector<Projectile>& projectileVector) {
    float angleToTarget = previousAngle, distance = 0.0f;
    
    if (isShop == true) {
        return;
    }

    if (target != nullptr && target->getCurHealth() <= 0) {
        target = nullptr;
    }
    // acquire/maintain target  //
    target = getTarget(enemyVector, priorityType);
    //                          //

    // 
    if (target != nullptr) {
        //std::cout << "locked on" << std::endl;
        distance = targetingFeed(this->getPosition(), target->getPosition(), &angleToTarget);
        if (distance > fireRange) {
            target = nullptr;
        }
    }

    // angle setting    //
    this->setRotation(angleToTarget);
    previousAngle = angleToTarget;
    //                  //

    // update and fire weapon   //
    mTime++;
    if (mTime >= fireRate && target != nullptr) {
        fireProjectile(projectileVector);
        mTime = 0;
    }
    //                          //
}