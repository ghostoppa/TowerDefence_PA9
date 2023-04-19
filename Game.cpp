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
    if (playerLives < 1)
    {
        return true;
    }
    else return false;
}

void Game::runLvl1(sf::RenderWindow& window)
{
    int round = 0;

    AssetManager assets;
    std::vector<Enemy> enemyVector;

    Map* testMap = nullptr;
    try
    {
        assets.loadTexture("testmap", "assets/img/testmap.png");
        testMap = new Map(assets.getTexture("testmap"), "assets/data/testmap/path.txt", "assets/data/testmap/hitboxes.txt");
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
            window.clear();
            window.draw(*testMap);

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