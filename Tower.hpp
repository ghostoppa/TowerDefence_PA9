#pragma once
#include <iostream>
#include <math.h>

#include "Damage.hpp"
#include "Definitions.hpp"
#include "Enemy.hpp"
#include "Entity.hpp"
#include "ColissionDetector.hpp"

class Projectile;

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
        isShop = false;
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

    void setPos(const sf::Vector2f& position);

    int getKills();
    void addKill();
    int getPrice();
    float getRange();
    sf::CircleShape* getRangeCircle();
    void showRadius(int valid);
    void showRadius(float range);

    void update(std::vector<Enemy>& enemyVector, std::vector<Projectile>& projectileVector);

    //void render() override;

protected:
    bool isShop;
    sf::CircleShape* rangeCircle;
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

class Projectile : public Entity, public sf::Sprite {
public:
    Projectile(Tower* tParent, sf::Texture& texture, const sf::Vector2f& position, float angle, int damage, float range, float velocity, float pAOE, int pChain, int pPierce) {
        // initializer  //
            // stats    //
        tDamage = damage;
        fireRange = range;
        fireVelocity = velocity / 60;
        tTime = 0;      // it is tea time, enjoy some tea
        //          //
        // metadata //
        projectileTexture = texture;
        aoe = pAOE;
        chain = pChain;
        pierce = pPierce + 1;
        firedAngle = angle;
        parent = tParent;
        //          //
    //              //

        markDestroy = false;
        setTexture(texture, true);
        this->setOrigin(2, (float)texture.getSize().y / 2);
        this->setRotation(firedAngle);
        this->setPosition(position.x + (getXComponent(angle) * 15), position.y + (getYComponent(angle) * 15));
        //
    };

    float getXComponent(float angle);
    float getYComponent(float angle);

    void getCorners(sf::Vector2f bottomRightCorner, sf::Vector2f topLeftCorner);
    bool collisionDetection(sf::Vector2f bottomRightCorner, sf::Vector2f topLeftCorner);

    bool update(std::vector<Enemy>& enemyVector, std::vector<Projectile>& projectileVector);

    void render() override;

private:
    bool markDestroy;
    float fireRange;
    float fireRate;
    float fireVelocity;
    float firedAngle;
    float aoe;
    int chain;
    int pierce;
    int tTime;
    int tDamage;
    Damage towersDamage;
    sf::Texture projectileTexture;
    Tower* parent;
};