#pragma once
#include "../Headers/Entity.hpp"

class Enemy : public Entity
{
public:
    void update() override;
    void render() override;

};

