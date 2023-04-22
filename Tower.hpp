#pragma once
#include <iostream>
#include <math.h>

#include "Damage.hpp"
#include "Enemy.hpp"
#include "Entity.hpp"


class Tower : public Entity, public sf::Sprite
{
public:
    Tower(sf::Texture& texture, int damage, float secondsPerShot, float range, int targetPriority) {
        // initializer  //
            // stats    //
        mDamage = damage;
        fireRate = secondsPerShot * 1000;
        fireRange = range;
        mTime = 0;
        //          //
        // metadata //
        previousAngle = 0.0f;
        previousDistanceToTarget = range;
        priorityType = targetPriority;
        target = nullptr;
        //          //
    //              //

        setTexture(texture, true);
        this->setOrigin(20.0f, 20.0f);
        this->setPosition(400.0f, 200.0f);
        std::cout << "turret online" << std::endl;
    };

    float targetingFeed(const sf::Vector2f& pointMain, const sf::Vector2f& pointTarget);
    float targetingFeed(const sf::Vector2f& pointMain, const sf::Vector2f& pointTarget, float* angle);

    Enemy* targetClosest(std::vector<Enemy>& enemyVector);
    Enemy* targetFirst(std::vector<Enemy>& enemyVector);
    Enemy* targetLast(std::vector<Enemy>& enemyVector);

    Enemy* getTarget(std::vector<Enemy>& enemyVector, int priorityType);

    void update(std::vector<Enemy>& enemyVector);

    void render() override;

private:
    int mDamage;
    Damage towersDamage;
    float fireRate;
    float fireRange;
    int priorityType;
    Enemy* target;
    float previousAngle;
    float previousDistanceToTarget;
    int mTime;
};