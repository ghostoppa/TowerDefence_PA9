#include <SFML/Graphics.hpp>
#include "../Headers/LinearPath.h"
#include "../Headers/Enemy.hpp"
#include "../Headers/Map.h"
#include <iostream>
#include <time.h>
int main()
{
    sf::RenderWindow window(sf::VideoMode(640 , 480), "Game");
    //Set framerate to MAX 60fps
    window.setFramerateLimit(60);
    Map* testMap = new Map("assets/img/testmap.png", "assets/data/testmap/path.txt", "assets/data/testmap/hitboxes.txt");
    /*------ TEST CODE FOR MULTIPLE ENEMY MOVEMENT --------*/
    //(This can be deleted when we don't need it anymore)
    //Basically I'm setting the time to 0, and then creating a test path

    //srand((unsigned int)time(0));
    //bool path_complete = false;
    //sf::Vector2f target;
    //LinearPath testPath;
    ////(The path is just a square)
    //testPath.addPoint(sf::Vector2f(10, 10));
    //testPath.addPoint(sf::Vector2f(600, 10));
    //testPath.addPoint(sf::Vector2f(600, 440));
    //testPath.addPoint(sf::Vector2f(10, 440));
    //testPath.addPoint(sf::Vector2f(10, 10));

    std::vector<Enemy> enemies;
    std::vector<Enemy>::iterator enemies_it;
    //Create a bunch of random enemies
    for (int i = 0; i < 500; ++i)
    {
        enemies.push_back(Enemy(1 + rand() % 50, 0.5 + (float)(rand()) / (float)(rand()), testMap->getPath()));
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

        window.clear();
        window.draw(*testMap);

        //Enemy creation loop
        for (enemies_it = enemies.begin(); enemies_it < enemies.end(); enemies_it++)
        {
            if (enemies_it->finished_path())
            {
                enemies.erase(enemies_it);   
            }
            else
            {
                enemies_it->update();
                window.draw(*enemies_it);
            }

        }
        window.display();
    }

    return 0;
}