#pragma once
#include "../Headers/Entity.hpp"
#include "Damage.hpp"



class Tower : public Entity
{
    void update() override;

    void render() override;

private:
    int damage;
    Damage towersDamage;
}



