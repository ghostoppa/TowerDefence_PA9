#pragma once
#include "Tower.hpp"

class Sprayer : public Tower {
public:
    Sprayer(sf::Texture& texture, sf::Texture& tProjectile, const sf::Vector2f& position, bool shop) {
        // initializer  //
            // stats    //
            fireRate = .33f * 60;        // seconds * framerate so that mTime can properly time shots
            fireRange = SPRAYER_RANGE;          // range of turret
            mTime = 0;
            projectile = &tProjectile;  // projectile texture
            mDamage = 1;
            projectileChainRange = 0;   // useless for non ARC weapons
            projectileVelocity = 0;     // sprayer projectile is static from aim
            projectileAOE = 75.0f;      // default for sprayer is it's range
            projectileChain = 0;        // useless for a sprayer
            projectilePierce = 0;       // useless for a sprayer
            mPrice = SPRAYER_PRICE;      // defined in Definitions.hpp
            //          //
            // metadata //
            previousAngle = 0.0f;
            previousDistanceToTarget = 75.0f;
            priorityType = 1;           // default for sprayers is closest targeting
            target = nullptr;
            rangeCircle = new sf::CircleShape(fireRange, 32);
            rangeCircle->setFillColor(sf::Color(100, 100, 100, 0));
            //          //
        //              //

        setTexture(texture, true);
        this->setOrigin(20.0f, 20.0f);
        this->setPosition(position.x + 20, position.y + 20);
        std::cout << "turret online" << std::endl;
    };

private:
};