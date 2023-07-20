#pragma once
#include "Tower.hpp"

class FlameThrower : public Tower {
public:
    FlameThrower(sf::Texture& texture, sf::Texture& tProjectile, const sf::Vector2f& position, bool shop) {
        // initializer  //
            // stats    //
            fireRate = .75f * 60;       // seconds * framerate so that mTime can properly time shots
            fireRange = FLAME_THROWER_RANGE;         // range of turret
            mTime = 0;
            projectile = &tProjectile;  // projectile texture
            mDamage = 5;
            projectileChainRange = 0;   // useless for non ARC weapons
            projectileVelocity = 1000;  // this is the speed of projectile in meters per second, it actually works kinda well
            projectileAOE = 0;          // default for kinetics is 0, first HE upgrade should be 10 pixel radius
            projectileChain = 0;        // this would act as ricochet and need a specialized projectile class
            projectilePierce = 0;       // default pierce for a particle cannon is 2
            mPrice = FLAME_THROWER_PRICE;       // defined in Definitions.hpp
            //          //
            // metadata //
            previousAngle = 0.0f;
            previousDistanceToTarget = 150;
            priorityType = 1;           // default for particle cannons is strong targeting
            target = nullptr;
            isShop = shop;
            rangeCircle = new sf::CircleShape(fireRange, 32);
            rangeCircle->setFillColor(sf::Color(100, 100, 100, 100));
            //          //
        //              //

        setTexture(texture, true);
        this->setOrigin(20.0f, 20.0f);
        this->setPosition(position.x + 20, position.y + 20);
        std::cout << "turret online" << std::endl;
    };
};