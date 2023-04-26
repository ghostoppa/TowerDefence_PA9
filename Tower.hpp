#pragma once
#include <iostream>
#include <math.h>

#include "Damage.hpp"
#include "Definitions.hpp"
#include "Enemy.hpp"
#include "Entity.hpp"
#include "Projectile.h"


class Tower : public Entity, public sf::Sprite {
public:
    Tower() {
        // initializer  //
            // stats    //
            fireRate = 1 * 60;
            fireRange = 150;
            mTime = 0;
            projectile = nullptr;
            mDamage = 5;
            projectileChainRange = 50;
            projectileVelocity = 1000;
            projectileAOE = 0;
            projectileChain = 0;
            projectilePierce = 2;
            mPrice = 0;
            mKills = 0;
            //          //
            // metadata //
            previousAngle = 0.0f;
            previousDistanceToTarget = 150;
            priorityType = 0;
            target = nullptr;
            //          //
        //              //
    };

    float targetingFeed(const sf::Vector2f& pointMain, const sf::Vector2f& pointTarget);
    float targetingFeed(const sf::Vector2f& pointMain, const sf::Vector2f& pointTarget, float* angle);

    Enemy* targetClosest(std::vector<Enemy>& enemyVector);
    Enemy* targetFirst(std::vector<Enemy>& enemyVector);
    Enemy* targetLast(std::vector<Enemy>& enemyVector);
    Enemy* targetLock(std::vector<Enemy>& enemyVector);
    Enemy* targetStrong(std::vector<Enemy>& enemyVector);

    Enemy* getTarget(std::vector<Enemy>& enemyVector, int priorityType);

    void fireProjectile(std::vector<Projectile>& projectileVector);

    int getKills();
    int getPrice();
    float getRange();

    void update(std::vector<Enemy>& enemyVector, std::vector<Projectile>& projectileVector);

    void render() override;

protected:
    int mDamage;
    Damage towersDamage;
    sf::Texture* projectile;
    float projectileChainRange;
    float projectileVelocity;
    float projectileAOE;
    int projectileChain;
    int projectilePierce;
    float fireRate;
    float fireRange;
    int priorityType;
    Enemy* target;
    float previousAngle;
    float previousDistanceToTarget;
    int mTime;
    int mKills;
    int mPrice;
};