#include <SFML/Graphics.hpp>
#include "../Headers/LinearPath.h"
#include "../Headers/Enemy.hpp"
#include <iostream>
#include <time.h>
int main()
{
    sf::RenderWindow window(sf::VideoMode(640 , 480), "Game");
    //Set framerate to MAX 60fps
    window.setFramerateLimit(60);
    /*------ TEST CODE FOR MULTIPLE ENEMY MOVEMENT --------*/
    //(This can be deleted when we don't need it anymore)
    //Basically I'm setting the time to 0, and then creating a test path

    srand(time(0));
    bool path_complete = false;
    sf::Vector2f target;
    LinearPath testPath;
    //(The path is just a square)
    testPath.addPoint(sf::Vector2f(10, 10));
    testPath.addPoint(sf::Vector2f(600, 10));
    testPath.addPoint(sf::Vector2f(600, 440));
    testPath.addPoint(sf::Vector2f(10, 440));
    testPath.addPoint(sf::Vector2f(10, 10));

    std::vector<Enemy*> enemies;
    for (int i = 0; i < 4; ++i)
    {
        enemies.push_back(new Enemy(20, (float)(rand()) / (float)(rand()), testPath));
    }
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