#pragma once
#include "Entity.hpp"
#include "LinearPath.hpp"

class Enemy : public Entity, public sf::Sprite
{
public:
    Enemy(sf::Texture& texture, int health, float speed, LinearPath& path) : mHealth(health), mMaxHealth(health), mSpeed(speed), mPath(path)
    {
        this->setTexture(texture);
        this->setOrigin(5.0f, 5.0f);
        mTime = 0;
        completed_path = false;
    };

    int getCurHealth();
    int getMaxHealth();

    void addHealth(int num);
    void subHealth(int num);

    ~Enemy() = default;

    float rotation();
    void update() override;

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

