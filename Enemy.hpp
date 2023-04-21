#pragma once
#include "Entity.hpp"
#include "LinearPath.hpp"

class Enemy : public Entity, public sf::CircleShape
{
public:
    Enemy(int health, float speed, LinearPath& path) : mHealth(health), mMaxHealth(health), mSpeed(speed), mPath(path)
    {
        this->setRadius(10.0f);
        if (health >= 20) {
            this->setFillColor(sf::Color::Red);
        }
        else if(health >= 10)
        {
            this->setFillColor(sf::Color::Yellow);
        }
        else
        {
            this->setFillColor(sf::Color::Green);
        }
            
        
        this->setOrigin(5.0f, 5.0f);
        mTime = 0;
        completed_path = false;
    };

    int getCurHealth();
    int getMaxHealth();

    ~Enemy() = default;
    void update() override;

    //Maybe we won't need this?
   // void render() override;

    bool isDefeated();

    bool finished_path() { return completed_path; };
    
private:
    LinearPath mPath;
    int mMaxHealth;
    int mHealth;

    float mTime;
    bool completed_path;
    float mSpeed;

};

