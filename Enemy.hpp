#pragma once
#include "Entity.hpp"
#include "LinearPath.h"

class Enemy : public Entity, public sf::CircleShape
{
public:
    Enemy(int health, float speed, LinearPath* path) : mHealth(health), mSpeed(speed), mPath(path)
    {
        this->setRadius(10.0f);
        if (health > 40) {
            this->setFillColor(sf::Color::Red);
        }
        else if(health > 20)
        {
            this->setFillColor(sf::Color::Yellow);
        }
        else if (health > 0)
        {
            this->setFillColor(sf::Color::Green);
        }
            
        
        this->setOrigin(5.0f, 5.0f);
        mTime = 0;
        completed_path = false;
    };

    ~Enemy() = default;
    void update() override;

    //Maybe we won't need this?
    void render() override;

    bool finished_path() { return completed_path; };
    
private:
    LinearPath *mPath;
    int mHealth;
    float mTime;
    bool completed_path;
    float mSpeed;
};

