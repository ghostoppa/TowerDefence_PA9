#include <SFML/Graphics.hpp>

#include <iostream>
#include <time.h>

#include "LinearPath.hpp"
#include "Enemy.hpp"
#include "Map.hpp"
#include "AssetManager.hpp"
#include "Definitions.hpp"
#include "Game.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH , SCREEN_HEIGHT), "Game");
    //Set framerate to MAX 60fps
    window.setFramerateLimit(60);
    
    system("echo %cd%");

    /////Implementation of game class, comment out to run Dante's test run
    /////Game class unfinished, need to implement accurate damage, enemy progression
    /////and tower placement, along with many other things lol
    Game newGame;
    newGame.startGame(LEVEL1, window);

    AssetManager assets;
    Map* testMap = nullptr;
    try
    {
        assets.loadTexture("testmap", "assets/img/map1.png");
        testMap = new Map(assets.getTexture("testmap"), "assets/data/testmap/path.txt", "assets/data/testmap/hitboxes.txt");
    }
    catch (FileLoadError& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::vector<Enemy> enemies;
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
        for (int i = 0; i < enemies.size(); ++i)
        {

            if (enemies.at(i).finished_path())
            {
                    enemies.erase(enemies.begin() + i);
            }
            else
            {
                enemies.at(i).update();
                window.draw(enemies.at(i));
            }

        }
        window.display();
    }

    return 0;
}