#include "GameState.hpp"
GameState::GameState(GameDataRef ref) : data(ref)
{
	
	debugLivesText = nullptr;
	//testTower = nullptr;
	testMap = nullptr;
	debugLivesText = nullptr;
	debugMoneyText = nullptr;
	debugRoundsText = nullptr;
	isMoving = false;
	mMoney = 0;
	playerLives = 100;
	round = 1;
	time = 0;

}

void GameState::Init()
{
	try
	{
		//weird file loading error?
		
		this->data->assets.loadTexture("Tower1", TOWER_ONE);
		this->data->assets.loadTexture("Tower2", TOWER_TWO);
		this->data->assets.loadTexture("Tower3", TOWER_THREE);
		this->data->assets.loadTexture("Tower4", TOWER_FOUR);
		this->data->assets.loadTexture("Tower5", TOWER_FIVE);
		this->data->assets.loadTexture("Tower6", TOWER_SIX);
		this->data->assets.loadTexture("Map1", Map1File);

		this->towerArr[0].setTexture(data->assets.getTexture("Tower1"));
		this->towerArr[1].setTexture(data->assets.getTexture("Tower2"));
		this->towerArr[2].setTexture(data->assets.getTexture("Tower3"));
		this->towerArr[3].setTexture(data->assets.getTexture("Tower4"));
		this->towerArr[4].setTexture(data->assets.getTexture("Tower5"));
		this->towerArr[5].setTexture(data->assets.getTexture("Tower6"));
		
		this->data->assets.loadFont("roboto", RobotoNormal);

		//this->data->turretVector.push_back(*testTower);
		testMap = new Map(data->assets.getTexture("Map1"), "assets/data/map1/path.txt", "assets/data/map1/hitboxes.txt");

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
	catch(FileLoadError &e){
		std::cout << e.what() << std::endl;
	}
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

void GameState::Draw()
{
	this->data->window.clear(sf::Color::Red);
	this->data->window.draw(*testMap);
	if (debugLivesText)
	{
		debugLivesText->setString("Lives: " + std::to_string(playerLives));
		this->data->window.draw(*debugLivesText);
	}
	for (int i = 0; i < 6; i++)
	{
		this->data->window.draw(this->towerArr[i]);
	}
	this->data->window.display();
}

void GameState::doIconMove()
{
	for(int i =0; i<6; i++)
	if (this->data->inputs.IsSpriteClicked(this->towerArr[i], sf::Mouse::Left, this->data->window))
	{
	this->towerArr[i].setPosition((float) sf::Mouse::getPosition().x, (float) sf::Mouse::getPosition().y);
	this->isMoving = true;
	break;
	}
}

bool GameState::isGameOver()
{
	return playerLives < 1;
}

void GameState::Update()
{
	
	//Round cur_round(round * round, 20, 7, 20);
	if (!isGameOver()) {
		/*cur_round.fetchEnemy(time, this->data->enemyVector, *testMap->getPath(), round);

		for (int i = 0; i < this->data->enemyVector.size(); ++i)
		{
			if (this->data->enemyVector.at(i).finished_path())
			{
				playerLives -= this->data->enemyVector.at(i).getCurHealth();
				this->data->enemyVector.erase(this->data->enemyVector.begin() + i);
			}
			else if (this->data->enemyVector.at(i).isDefeated())
			{
				mMoney += data->enemyVector.at(i).getMaxHealth();
				data->enemyVector.erase(data->enemyVector.begin() + i);
			}
			else
			{
				data->enemyVector.at(i).update();
			}
		}*/
	}
	//this->data->machine.AddState(StateRef(new EndGameState), true);
}

	
