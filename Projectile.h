#pragma once
#include <iostream>
#include <math.h>

#include "Damage.hpp"
#include "Enemy.hpp"
#include "Entity.hpp"
class Projectile : public Entity, public sf::Sprite {
public:
    Projectile(sf::Texture& texture, const sf::Vector2f& position, float angle, int damage, float range, float velocity, float pAOE, int pChain, int pPierce) {
        // initializer  //
            // stats    //
            tDamage = damage;
            fireRange = range;
            fireVelocity = velocity/60;
            tTime = 0;      // it is tea time, enjoy some tea
            //          //
            // metadata //
            projectileTexture = texture;
            aoe = pAOE;
            chain = pChain;
            pierce = pPierce + 1;
            firedAngle = angle;
            //          //
        //              //
        
        setTexture(texture, true);
        this->setOrigin(2, texture.getSize().y / 2);
        this->setRotation(firedAngle);
        this->setPosition(position.x + (getXComponent(angle) * 15), position.y + (getYComponent(angle) * 15));
        //

    };

    float getXComponent(float angle);
    float getYComponent(float angle);

    bool update(std::vector<Enemy>& enemyVector, std::vector<Projectile>& projectileVector);

    void render() override;

private:
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
};

