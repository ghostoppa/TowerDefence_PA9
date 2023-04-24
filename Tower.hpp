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
    Tower(sf::Texture& texture, sf::Texture& tProjectile, const sf::Vector2f& position, float secondsPerShot, float range, int targetPriority, int damage, float velocity) {
        // initializer  //
            // stats    //
            fireRate = secondsPerShot * 60;
            fireRange = range;
            mTime = 0;
            projectile = &tProjectile;
            mDamage = damage;
            projectileRange = 50;
            projectileVelocity = velocity;
            projectileAOE = 0;
            projectileChain = 0;
            projectilePierce = 2;
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
        this->setPosition(position.x + 20, position.y + 20);
        std::cout << "turret online" << std::endl;
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

    void update(std::vector<Enemy>& enemyVector, std::vector<Projectile>& projectileVector);

    void render() override;

private:
    int mDamage;
    Damage towersDamage;
    sf::Texture* projectile;
    float projectileRange;
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
};