#include "Game.hpp"

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
    int round = 0;

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

    while (!isGameOver())
    {
        this->genEnemyForces(enemyVector, testMap, round);

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
            if (debugLivesText)
            {
                debugLivesText->setString("Lives: " + std::to_string(playerLives));
                window.draw(*debugLivesText);
            }
            for (int i = 0; i < enemyVector.size(); ++i)
            {

                if (enemyVector.at(i).finished_path())
                {
                    enemyVector.erase(enemyVector.begin() + i);
                    this->playerLives--;
                }
                else
                {
                    enemyVector.at(i).update();
                    window.draw(enemyVector.at(i));
                }
            }
            window.display();
            if (enemyVector.size() == 0) break;
        }

        round++;
    }
    std::cout << round << std::endl;
}

void Game::genEnemyForces(std::vector<Enemy>& enemyVector, Map*& map, int& round)
{
    enemyVector.clear();

    for (int i = 0; i < 25; ++i)
    {
        enemyVector.push_back(Enemy(1 + rand() % 50, 5.5 + (float)(rand()) / (float)(rand()), map->getPath()));
    }
}