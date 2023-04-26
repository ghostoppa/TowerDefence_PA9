#pragma once
#include "Tower.hpp"

class ParticleCannon : public Tower {
public:
    ParticleCannon(sf::Texture& texture, sf::Texture& tProjectile, const sf::Vector2f& position) {
        // initializer  //
            // stats    //
            fireRate = 1.5f * 60;       // seconds * framerate so that mTime can properly time shots
            fireRange = 300.0f;         // range of turret
            mTime = 0;
            projectile = &tProjectile;  // projectile texture
            mDamage = 20;
            projectileChainRange = 0;   // useless for non ARC weapons
            projectileVelocity = 2500;  // this is the speed of projectile in meters per second, it actually works kinda well
            projectileAOE = 0;          // default for kinetics is 0, first HE upgrade should be 10 pixel radius
            projectileChain = 0;        // this would act as ricochet and need a specialized projectile class
            projectilePierce = 2;       // default pierce for a particle cannon is 2
            mPrice = pCanPrice;         // defined in Definitions.hpp
            //          //
            // metadata //
            this->previousAngle = 0.0f;
            previousDistanceToTarget = 300;
            priorityType = 4;           // default for particle cannons is strong targeting
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

