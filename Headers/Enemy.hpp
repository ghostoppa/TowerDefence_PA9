#pragma once
#include "Entity.hpp"

class Enemy : public Entity
{
public:
    Enemy(int health, int speed) : mHealth(health), mSpeed(speed)
    {
    };
    void update() override;
    void render() override;
    
private:
    int mHealth;
    int mSpeed;
};

