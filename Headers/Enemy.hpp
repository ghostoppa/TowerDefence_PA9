#pragma once
#include "Entity.hpp"
#include "LinearPath.h"

class Enemy : public Entity
{
public:
    Enemy(int health, float speed, LinearPath path) : mHealth(health), mSpeed(speed), mPath(path)
    {
        this->setSize(sf::Vector2f(10, 10));
        this->setFillColor(sf::Color::Red);
        mTime = 0;
        completed_path = false;
    };
    void update() override;

    //Maybe we won't need this?
    void render() override;
    
private:
    LinearPath mPath;
    int mHealth;
    float mTime;
    bool completed_path;
    float mSpeed;
};

