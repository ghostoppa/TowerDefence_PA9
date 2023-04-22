#include "GameState.hpp"

void GameState::Init()
{
	try
	{
		this -> data->assets.loadTexture("Tower1", TOWER_ONE);
			this->data->assets.loadTexture("Tower1", TOWER_ONE);
			this->data->assets.loadTexture("Tower2", TOWER_TWO);
			this->data->assets.loadTexture("Tower3", TOWER_THREE);
			this->data->assets.loadTexture("Tower4", TOWER_FOUR);
			this->data->assets.loadTexture("Tower5", TOWER_FIVE);
			this->data->assets.loadTexture("Tower6", TOWER_SIX);

		/*	this->towerArr[0].setTexture(data->assets.getTexture("Tower1"));
			this->towerArr[1].setTexture(data->assets.getTexture("Tower2"));
			this->towerArr[2].setTexture(data->assets.getTexture("Tower3"));
			this->towerArr[3].setTexture(data->assets.getTexture("Tower4"));
			this->towerArr[4].setTexture(data->assets.getTexture("Tower5"));
			this->towerArr[5].setTexture(data->assets.getTexture("Tower6"));*/
			
			this->data->assets.loadFont("roboto", RobotoNormal);

			 sf	::Text* debugLivesText = nullptr;
    sf::Text* debugMoneyText = nullptr;
    sf::Text* debugRoundsText = nullptr;

			Tower* testTower = nullptr;
			Map* testMap = nullptr;
			this->data->turretVector.push_back(*testTower);

		this->data->assets.loadFont("roboto", RobotoNormal);
			debugLivesText = new sf::Text("Lives: ", data->assets.getFont("roboto"), 24);
			debugLivesText->setPosition(0, 0);
			debugLivesText->setFillColor(sf::Color::Blue);
			debugMoneyText = new sf::Text("Money: ", data->assets.getFont("roboto"), 24);
			debugMoneyText->setPosition(0, 25);
			debugMoneyText->setFillColor(sf::Color::Blue);
			debugRoundsText = new sf::Text("Money: ", data->assets.getFont("roboto"), 24);
			debugRoundsText->setPosition(530, 0);
			debugRoundsText->setFillColor(sf::Color::Blue);

			sf::Vector2f size(60, 60), position(50, 50);
		
	}
	catch(FileLoadError &e){}
}

void GameState::HandleInput()
{
	sf::Event event;

	while (this->data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->data->window.close();
		}
		//Logic to be added to place on right click;
		this->doIconMove();
		
	}
	}

void GameState::doIconMove()
{
	for(int i =0; i<6; i++)
	if (this->data->inputs.IsSpriteClicked(this->towerArr[i], sf::Mouse::Left, this->data->window))
	{
	this->towerArr[i].setPosition(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);
	this->isMoving = true;
	break;
	}
}

void GameState::Update()
{
	Round cur_round(round * round, 20, 7, 20);
	cur_round.fetchEnemy(time, this->data->enemyVector, *testMap->getPath(), round);

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
		window.clear();
		window.draw(*testMap);

		if (debugLivesText)
		{
			debugLivesText->setString("Lives: " + std::to_string(playerLives));
			window.draw(*debugLivesText);
		}
}