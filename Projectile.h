#pragma once
#include <iostream>

#include "Damage.hpp"
#include "Enemy.hpp"
#include "Entity.hpp"
class Projectile : public Entity, public sf::Sprite {
    Projectile(sf::Texture& texture, float angle, int damage, float range, float pAOE, int pChain, int pPierce) {
        // initializer  //
            // stats    //
            tDamage = damage;
            fireRange = range;
            tTime = 0;      // it is tea time, enjoy some tea
            //          //
            // metadata //
            projectileTexture = texture;
            aoe = pAOE;
            chain = pChain;
            pierce = pPierce;
            firedAngle = angle;
            //          //
        //              //

        setTexture(texture, true);
        this->setOrigin(20.0f, 20.0f);
        this->setPosition(400.0f, 200.0f);
        std::cout << "turret online" << std::endl;
    };
private:
    float fireRange;
    float fireRate;
    float firedAngle;
    float aoe;
    int chain;
    int pierce;
    int tTime;
    int tDamage;
    Damage towersDamage;
    sf::Texture projectileTexture;
};

