#include "GameState.hpp"
GameState::GameState(GameDataRef ref) : data(ref)
{
	cur_round = nullptr;
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

			this->data->curSound.stop();
		this->data->curSound.openFromFile(gameSound);
	this->data->curSound.play();
	this->data->curSound.setLoop(true);
	try
	{
		
		
		this->data->assets.loadTexture("Tower1", TOWER_ONE);
		this->data->assets.loadTexture("Tower2", TOWER_TWO);
		this->data->assets.loadTexture("Tower3", TOWER_THREE);
		this->data->assets.loadTexture("Tower4", TOWER_FOUR);
		this->data->assets.loadTexture("Tower5", TOWER_FIVE);
		this->data->assets.loadTexture("Tower6", TOWER_SIX);
		this->data->assets.loadTexture("Map1", Map1File);
		this->data->assets.loadTexture("MenuBackground", MENUBACKGROUND);

		this->towerArr[0].setTexture(data->assets.getTexture("Tower1"));
		this->towerArr[1].setTexture(data->assets.getTexture("Tower2"));
		this->towerArr[2].setTexture(data->assets.getTexture("Tower3"));
		this->towerArr[3].setTexture(data->assets.getTexture("Tower4"));
		this->towerArr[4].setTexture(data->assets.getTexture("Tower5"));
		this->towerArr[5].setTexture(data->assets.getTexture("Tower6"));
		this->menuBackGround.setTexture(data->assets.getTexture("MenuBackground"));

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

		this->menuBackGround.setPosition(520, -20);
		this->menuBackGround.setColor(sf::Color(255, 255, 255, 200));
		this->menuBackGround.setScale(.8, .8);
			
			towerArr[0].setPosition(580*(1.0 * this->data->window.getSize().x / SCREEN_WIDTH),
				20 * (1.0*this->data->window.getSize().y) / SCREEN_HEIGHT);
			towerArr[1].setPosition(580 * (1.0 * this->data->window.getSize().x / SCREEN_WIDTH),
				100 * (1.0 * this->data->window.getSize().y) / SCREEN_HEIGHT);
			towerArr[2].setPosition(580 * (1.0 * this->data->window.getSize().x / SCREEN_WIDTH),
				180 * (1.0 * this->data->window.getSize().y) / SCREEN_HEIGHT);
			towerArr[3].setPosition(580 * (1.0 * this->data->window.getSize().x / SCREEN_WIDTH),
				270*(1.0 * this->data->window.getSize().y) / SCREEN_HEIGHT);
			towerArr[4].setPosition(580 * (1.0 * this->data->window.getSize().x / SCREEN_WIDTH),
				354 * (1.0 * this->data->window.getSize().y) / SCREEN_HEIGHT);
			towerArr[5].setPosition(580 * (1.0 * this->data->window.getSize().x / SCREEN_WIDTH),
				430 * (1.0 * this->data->window.getSize().y) / SCREEN_HEIGHT);
		sf::Vector2f size(60, 60), position(50, 50);
		
		cur_round = new Round(round * round, 20, 7, 20);
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
	this->data->window.clear();
	this->data->window.clear(sf::Color::White);
	this->data->window.draw(*testMap);

	for (Enemy e : this->data->enemyVector)
	{
		this->data->window.draw(e);
	}

	if (debugLivesText)
	{
		debugLivesText->setString("Lives: " + std::to_string(playerLives));
		this->data->window.draw(*debugLivesText);
	}
		this->data->window.draw(menuBackGround);


	for (sf::Sprite towers : towerArr){
		this->data->window.draw(towers);
			}
	this->data->window.display();
	}

void GameState::doIconMove()
{
	for (int i = 0; i < 6; i++) {
		if (this->data->inputs.IsSpriteClicked(this->towerArr[i], sf::Mouse::Left, this->data->window))
		{
			sf::Vector2i mousePos(sf::Mouse::getPosition(this->data->window));
			this->isMoving = true;
			this->towerArr[i].setPosition((float)(mousePos.x -
				this->towerArr[i].getTexture()->getSize().x / 2.0f), (float)(mousePos.y -
					this->towerArr[i].getTexture()->getSize().y / 2.0f));
			std::cout << " x: " << sf::Mouse::getPosition((this->data->window)).x << " y: " << sf::Mouse::getPosition((this->data->window)).y << std::endl;;
			break;
		}
	}
}

bool GameState::isGameOver()
{
	return playerLives < 1;
}

void GameState::Update()
{
	if (cur_round != nullptr)
	{
		if (cur_round->isDone(this->data->enemyVector))
		{
			++round;
			delete cur_round;
			cur_round = new Round(round * round, 20, 7, 20);
		}
	}
	
	if (!isGameOver()) {
		cur_round->fetchEnemy(time, this->data->enemyVector, *testMap->getPath(), round);

		for (int i = 0; i < this->data->enemyVector.size(); ++i)
		{
			if (this->data->enemyVector.at(i).finished_path())
			{
				//for debug purposes
				--playerLives;
				//playerLives -= this->data->enemyVector.at(i).getCurHealth();
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
		}
	}
	//this->data->machine.AddState(StateRef(new EndGameState), true);
}

	
