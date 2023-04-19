#include "Game.hpp"
#include "Round.h"

void Game::startGame(int level, sf::RenderWindow& window)
{
	switch (level)
	{
	case LEVEL1:
		runLvl1(window);
        break;
	}
}

bool Game::isGameOver()
{
    return playerLives < 1;
}

void Game::runLvl1(sf::RenderWindow& window)
{
    int round = 1;
    int time = 0;

    AssetManager assets;
    std::vector<Enemy> enemyVector;
    sf::Text* debugLivesText = nullptr;
   
    
    Map* testMap = nullptr;
    try
    {
        assets.loadTexture("map1", "assets/img/map1.png");
        testMap = new Map(assets.getTexture("map1"), "assets/data/map1/path.txt", "assets/data/map1/hitboxes.txt");
        assets.loadFont("roboto", "assets/fonts/Roboto-Regular.ttf");
        debugLivesText = new sf::Text("Lives: ", assets.getFont("roboto"), 24);
        debugLivesText->setPosition(0, 0);
        debugLivesText->setFillColor(sf::Color::Blue);
    }
    catch (FileLoadError& e)
    {
        std::cout << e.what() << std::endl;
    }
    sf::Vector2f size(60, 60), position(50, 50);
    Interactable testInteratable ( size, position);
   
    while (!isGameOver())
    {
        //this->genEnemyForces(enemyVector, testMap, round);
        Round cur_round(round * round, 20, 5, 20);
        
        while (window.isOpen() && !cur_round.isDone(enemyVector) && !isGameOver())
        {
            /*-----UPDATE SECTION: TRY NOT TO PUT DRAWING CODE HERE------*/
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            cur_round.fetchEnemy(time, enemyVector, *testMap->getPath());

            for (int i = 0; i < enemyVector.size(); ++i)
            {
                if (enemyVector.at(i).finished_path())
                {
                    this->playerLives--;
                    enemyVector.erase(enemyVector.begin() + i);
                }
                else
                {
                    enemyVector.at(i).update();
                }
            }
            /*-----DRAW SECTION: TRY NOT TO PUT UPDATE CODE HERE-----*/
            window.clear();
            window.draw(*testMap);
            
            window.draw(testInteratable);
            testInteratable.update();

            if (debugLivesText)
            {
                debugLivesText->setString("Lives: " + std::to_string(playerLives));
                window.draw(*debugLivesText);
            }

            //Comment out to see map hitboxes
            //testMap->renderHitBoxes(window);
            
            //(Separating the enemy draw loop and enemy update loop prevents flickering)
            for (Enemy e : enemyVector)
            {
                window.draw(e);
            }

            window.display();
            /*--------------------------------------------------------*/
        }
        if (window.isOpen())
        {
            std::cout << "Round " << round << " complete" << std::endl;
            round++;
        }
        else
        {
            //Closing the window triggers game over to exit loop
            break;
        }
    }
    if(window.isOpen()) window.close();
}

void Game::genEnemyForces(std::vector<Enemy>& enemyVector, Map*& map, int& round)
{
    enemyVector.clear();

    for (int i = 0; i < 25; ++i)
    {
        enemyVector.push_back(Enemy(1 + rand() % 50, 5.5f + (float)(rand()) / (float)(rand()), *map->getPath()));
    }
}