#include <SFML/Graphics.hpp>
#include "../Headers/LinearPath.h"
#include "../Headers/Enemy.hpp"
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(640 , 480), "Game");

    /*------ TEST CODE FOR MULTIPLE ENEMY MOVEMENT --------*/
    //(This can be deleted when we don't need it anymore)
    //Basically I'm setting the time to 0, and then creating a test path
    float time = 0;
    bool path_complete = false;
    sf::Vector2f target;
    LinearPath testPath;
    //(The path is just a square)
    testPath.addPoint(sf::Vector2f(320, 240));
    testPath.addPoint(sf::Vector2f(500, 240));
    testPath.addPoint(sf::Vector2f(500, 320));
    testPath.addPoint(sf::Vector2f(320, 320));
    testPath.addPoint(sf::Vector2f(320, 240));

    std::vector<Enemy*> enemies;
    enemies.push_back(new Enemy(20, 2, testPath));
    enemies.push_back(new Enemy(20, 1, testPath));
    enemies.push_back(new Enemy(20, 0.5, testPath));
    enemies.push_back(new Enemy(20, 0.3, testPath));
    /*-------------------------------------------*/

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        for (Enemy* i : enemies)
        {
            i->update();
        }

        window.clear();
        for (Enemy* i : enemies)
        {
            window.draw(*i);
        }
        window.display();
    }

    return 0;
}