#pragma once
#include "Entity.h"
class Enemy : public Entity
{
public:
    void update() override;
    void render() override;

};

