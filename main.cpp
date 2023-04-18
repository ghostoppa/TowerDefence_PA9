#include <SFML/Graphics.hpp>

#include <iostream>
#include <time.h>

#include "LinearPath.hpp"
#include "Enemy.hpp"
#include "Map.hpp"
#include "AssetManager.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(640 , 480), "Game");
    //Set framerate to MAX 60fps
    window.setFramerateLimit(60);
    
    AssetManager assets;
    assets.loadTexture("testmap", "assets/img/testmap.png");

    Map* testMap = new Map(assets.getTexture("testmap"), "assets/data/testmap/path.txt", "assets/data/testmap/hitboxes.txt");
    

    std::vector<Enemy> enemies;
    std::vector<Enemy>::iterator enemies_it;
    //Enemy test code
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