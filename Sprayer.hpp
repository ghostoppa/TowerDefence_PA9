#pragma once
#include "Tower.hpp"

class Sprayer : public Tower {
public:
    Sprayer(sf::Texture& texture, sf::Texture& tProjectile, const sf::Vector2f& position) {
        // initializer  //
            // stats    //
            fireRate = .2f * 60;        // seconds * framerate so that mTime can properly time shots
            fireRange = 75.0f;          // range of turret
            mTime = 0;
            projectile = &tProjectile;  // projectile texture
            mDamage = 1;
            projectileChainRange = 0;   // useless for non ARC weapons
            projectileVelocity = 0;     // sprayer projectile is static from aim
            projectileAOE = 75.0f;      // default for sprayer is it's range
            projectileChain = 0;        // useless for a sprayer
            projectilePierce = 0;       // useless for a sprayer
            mPrice = sprayerPrice;      // defined in Definitions.hpp

            //          //
            // metadata //
            previousAngle = 0.0f;
            previousDistanceToTarget = 75.0f;
            priorityType = 1;           // default for sprayers is closest targeting
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