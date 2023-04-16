#pragma once
#include "Entity.hpp"
#include "Damage.hpp"


class Tower : public Entity
{
public:
    Tower(int damage) : mDamage(damage)
    {
    };

    void update() override;

    void render() override;

private:
    int mDamage;
    Damage towersDamage;
};