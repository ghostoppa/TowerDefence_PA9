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
    std::vector<Tower> turretVector;
    sf::Text* debugLivesText = nullptr;
    sf::Text* debugMoneyText = nullptr;
    sf::Text* debugRoundsText = nullptr;
   

    Tower* testTower = nullptr;
    Map* testMap = nullptr;
    try
    {
        assets.loadTexture("map1", "assets/img/map1.png");
        testMap = new Map(assets.getTexture("map1"), "assets/data/map1/path.txt", "assets/data/map1/hitboxes.txt");

        assets.loadTexture("turret1", "assets/img/turret1.png");
        testTower = new Tower(assets.getTexture("turret1"), 20, 1.5, 200, 2);
        turretVector.push_back(*testTower);

        assets.loadFont("roboto", "assets/fonts/Roboto-Regular.ttf");
        debugLivesText = new sf::Text("Lives: ", assets.getFont("roboto"), 24);
        debugLivesText->setPosition(0, 0);
        debugLivesText->setFillColor(sf::Color::Blue);
        debugMoneyText = new sf::Text("Money: ", assets.getFont("roboto"), 24);
        debugMoneyText->setPosition(0, 25);
        debugMoneyText->setFillColor(sf::Color::Blue);
        debugRoundsText = new sf::Text("Money: ", assets.getFont("roboto"), 24);
        debugRoundsText->setPosition(530, 0);
        debugRoundsText->setFillColor(sf::Color::Blue);
    }
    catch (FileLoadError& e)
    {
        std::cout << e.what() << std::endl;
    }
    sf::Vector2f size(60, 60), position(50, 50);
    Interactable testInteractable( size, position);
   
    while (!isGameOver())
    {
        //this->genEnemyForces(enemyVector, testMap, round);
        Round cur_round(round * round, 20, 7, 20);
        
        while (window.isOpen() && !cur_round.isDone(enemyVector) && !isGameOver())
        {
            /*-----UPDATE SECTION: TRY NOT TO PUT DRAWING CODE HERE------*/
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            cur_round.fetchEnemy(time, enemyVector, *testMap->getPath(), round);

            for (int i = 0; i < enemyVector.size(); ++i)
            {
                if (enemyVector.at(i).finished_path())
                {
                    playerLives -= enemyVector.at(i).getCurHealth();
                    enemyVector.erase(enemyVector.begin() + i);
                }
                else if (enemyVector.at(i).isDefeated())
                {
                    mMoney += enemyVector.at(i).getMaxHealth();
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
      
            window.draw(testInteractable);
            testInteractable.update(window);

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
            for (Tower t : turretVector)
            {
                window.draw(t);
            }

            window.draw(testInteractable);

            if (debugLivesText)
            {
                debugLivesText->setString("Lives: " + std::to_string(playerLives));
                window.draw(*debugLivesText);
                debugMoneyText->setString("Money: " + std::to_string(mMoney));
                window.draw(*debugMoneyText);
                debugRoundsText->setString("Round: " + std::to_string(round));
                window.draw(*debugRoundsText);
            }

            window.display();
            /*--------------------------------------------------------*/
        }
        if (window.isOpen())
        {
            std::cout << "Round " << round << " complete" << std::endl;
            mMoney += 50 * round;
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