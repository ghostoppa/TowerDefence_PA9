#pragma once
#include "Tower.hpp"

class Zapper : public Tower {
public:
    Zapper(sf::Texture& texture, sf::Texture& tProjectile, const sf::Vector2f& position) {
        // initializer  //
            // stats    //
            fireRate = .66f * 60;       // seconds * framerate so that mTime can properly time shots
            fireRange = 50.0f;          // range of turret
            mTime = 0;
            projectile = &tProjectile;  // projectile texture
            mDamage = 3;
            projectileChainRange = 50;  // default for zapper is it's range maybe an upgrade for 1.5 or .05
            projectileVelocity = 0;     // zapper projectile is static and will spawn many projectiles that are modified to only check for target hit
            projectileAOE = 0;          // useless for a zapper
            projectileChain = 3;        // default for zapper is max of 3 targets to hit per shot
            projectilePierce = 0;       // useless for a zapper
            //          //
            // metadata //
            previousAngle = 0.0f;
            previousDistanceToTarget = 50.0f;
            priorityType = 1;           // default for particle cannons is strong targeting
            target = nullptr;
            //          //
        //              //

        setTexture(texture, true);
        this->setOrigin(20.0f, 20.0f);
        this->setPosition(position.x + 20, position.y + 20);
        std::cout << "turret online" << std::endl;
    };

private:
};