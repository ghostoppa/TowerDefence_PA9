#include "GameState.hpp"

GameState::GameState(GameDataRef ref) : data(ref)
{
	cur_round = nullptr;
	//testTower = nullptr;
	testMap = nullptr;
	debugLivesText = nullptr;
	debugMoneyText = nullptr;
	debugRoundsText = nullptr;

	isMoving = false;
	mMoney = 150;
	playerLives = 100;
	round = 1;
	time = 0;
	which = 0;
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
		//this->data->assets.loadTexture("Tower5", TOWER_FIVE);
		//this->data->assets.loadTexture("Tower6", TOWER_SIX);
		this->data->assets.loadTexture("Projectile1", PROJECTILE_ONE);
		this->data->assets.loadTexture("Projectile2", PROJECTILE_TWO);
		this->data->assets.loadTexture("Projectile3", PROJECTILE_THREE);
		this->data->assets.loadTexture("Projectile4", PROJECTILE_FOUR);
		this->data->assets.loadTexture("green", ENEMY_GREEN);
		this->data->assets.loadTexture("yellow", ENEMY_YELLOW);
		this->data->assets.loadTexture("red", ENEMY_RED);
		this->data->assets.loadTexture("Map1", Map1File);
		this->data->assets.loadTexture("MenuBackground", MENUBACKGROUND);

		this->towerArr[0].setTexture(data->assets.getTexture("Tower1"));
		this->towerArr[1].setTexture(data->assets.getTexture("Tower2"));
		this->towerArr[2].setTexture(data->assets.getTexture("Tower3"));
		this->towerArr[3].setTexture(data->assets.getTexture("Tower4"));
		//this->towerArr[4].setTexture(data->assets.getTexture("Tower5"));
		//this->towerArr[5].setTexture(data->assets.getTexture("Tower6"));

		this->menuBackGround.setTexture(data->assets.getTexture("MenuBackground"));

		this->data->assets.loadFont("roboto", RobotoNormal);
		this->data->assets.loadFont("myth", MythologyFont);

		testMap = new Map(data->assets.getTexture("Map1"), "assets/data/map1/path.txt", "assets/data/map1/hitboxes.txt");

		//Tower* testTower = new FlameThrower(data->assets.getTexture("Tower3"), data->assets.getTexture("Projectile3"), sf::Vector2f(400.0f, 200.0f));
		//data->turretVector.push_back(*testTower);

		/////Set text boxes/////
		debugLivesText = new sf::Text("Lives: ", data->assets.getFont("roboto"), 24);
		debugLivesText->setPosition(0, 0);
		debugLivesText->setFillColor(sf::Color::Blue);
		debugMoneyText = new sf::Text("Swats: ", data->assets.getFont("myth"), 24);
		debugMoneyText->setPosition(525, 43);
		debugMoneyText->setFillColor(sf::Color::Black);
		debugRoundsText = new sf::Text("Rounds: ", data->assets.getFont("roboto"), 24);
		debugRoundsText->setPosition(0, 25);
		debugRoundsText->setFillColor(sf::Color::Blue);

		this->menuBackGround.setPosition(512, 0);
		this->menuBackGround.setColor(sf::Color(255, 255, 255, 200));
		this->menuBackGround.setScale(.8f, .8f);
			
		towerArr[0].setPosition(560, 320);
		towerArr[1].setPosition(560, 428);
		towerArr[2].setPosition(560, 218);
		towerArr[3].setPosition(560, 112);

			/*towerArr[0].setPosition(580*(1.0 * this->data->window.getSize().x / SCREEN_WIDTH),
				20 * (1.0*this->data->window.getSize().y) / SCREEN_HEIGHT);
			towerArr[1].setPosition(580 * (1.0 * this->data->window.getSize().x / SCREEN_WIDTH),
				200 * (1.0 * this->data->window.getSize().y) / SCREEN_HEIGHT);
			towerArr[2].setPosition(580 * (1.0 * this->data->window.getSize().x / SCREEN_WIDTH),
				300 * (1.0 * this->data->window.getSize().y) / SCREEN_HEIGHT);
			towerArr[3].setPosition(580 * (1.0 * this->data->window.getSize().x / SCREEN_WIDTH),
				270*(1.0 * this->data->window.getSize().y) / SCREEN_HEIGHT);
			towerArr[4].setPosition(580 * (1.0 * this->data->window.getSize().x / SCREEN_WIDTH),
				354 * (1.0 * this->data->window.getSize().y) / SCREEN_HEIGHT);
			towerArr[5].setPosition(580 * (1.0 * this->data->window.getSize().x / SCREEN_WIDTH),
				430 * (1.0 * this->data->window.getSize().y) / SCREEN_HEIGHT);
			*/

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
	for (Tower t : this->data->turretVector)
	{
		this->data->window.draw(t);
	}
	for (Projectile p : this->data->projectileVector)
	{
		this->data->window.draw(p);
	}

	this->data->window.draw(menuBackGround);

	if (debugLivesText && debugMoneyText && debugRoundsText)
	{
		debugLivesText->setString("Lives: " + std::to_string(playerLives));
		this->data->window.draw(*debugLivesText);
		debugMoneyText->setString("Swats: " + std::to_string(mMoney));
		this->data->window.draw(*debugMoneyText);
		debugRoundsText->setString("Rounds: " + std::to_string(round));
		this->data->window.draw(*debugRoundsText);
	}

	for (sf::Sprite towers : towerArr)
	{
		this->data->window.draw(towers);
	}

	for (Tower displayTowers : this->placedTowers)
	{
		this->data->window.draw(displayTowers);
	}

	this->data->window.display();
}

void GameState::doIconMove()
{
	for (int i = 0; i < 4; i++) {
		if (this->data->inputs.IsSpriteClicked(this->towerArr[i], sf::Mouse::Left, this->data->window))
		{
			sf::Vector2i mousePos(sf::Mouse::getPosition(this->data->window));
			this->isMoving = true;
			this->towerArr[i].setPosition((float)(mousePos.x -
				this->towerArr[i].getTexture()->getSize().x / 2.0f), (float)(mousePos.y -
					this->towerArr[i].getTexture()->getSize().y / 2.0f));
			std::cout << " x: " << sf::Mouse::getPosition((this->data->window)).x << " y: " << sf::Mouse::getPosition((this->data->window)).y << std::endl;;
			break;
			this->towerArr[i].setColor(sf::Color(255, 255, 255, 200));
		}
			
	
		//This is supposed to see if it is in a hit box
		if (this->data->inputs.IsSpriteClicked(this->towerArr[i], sf::Mouse::Right, this->data->window))
		{
			std::vector<sf::RectangleShape> hitboxes = *(testMap->getHitboxes());
			for (sf::RectangleShape boxes : hitboxes)
			{

				sf::IntRect tempRect(towerArr[i].getPosition().x,
					towerArr[i].getPosition().y,
					towerArr[i].getGlobalBounds().width,
					towerArr[i].getGlobalBounds().height);
				if (boxes.getGlobalBounds().contains(tempRect.left, tempRect.top))
				{
					std::cout << "PUT IN HIT" << std::endl;
					switch (i)
					{
					case 0:
						if (mMoney >= SPRAYER_PRICE) {
							mMoney -= SPRAYER_PRICE;
							this->data->turretVector.push_back(Sprayer(this->data->assets.getTexture("Tower1"), this->data->assets.getTexture("Projectile1"), towerArr[i].getPosition()));
							towerArr[0].setPosition(560, 320);
							//towerArr[0].setPosition(580 * (1.0 * this->data->window.getSize().x / SCREEN_WIDTH),
								//20 * (1.0 * this->data->window.getSize().y) / SCREEN_HEIGHT);
						}
						else {
							std::cout << "not enough swats, swat some more" << std::endl;
						}
						break;
					case 1:
						if (mMoney >= PARTICLE_CANNON_PRICE) {
							mMoney -= PARTICLE_CANNON_PRICE;
							this->data->turretVector.push_back(ParticleCannon(this->data->assets.getTexture("Tower2"), this->data->assets.getTexture("Projectile2"), towerArr[i].getPosition()));
							towerArr[1].setPosition(560, 428);
							//towerArr[1].setPosition(580 * (1.0 * this->data->window.getSize().x / SCREEN_WIDTH),
								//100 * (1.0 * this->data->window.getSize().y) / SCREEN_HEIGHT);
						}
						else {
							std::cout << "not enough swats, swat some more" << std::endl;
						}
						break;
					case 2:
						if (mMoney >= FLAME_THROWER_PRICE) {
							mMoney -= FLAME_THROWER_PRICE;
							this->data->turretVector.push_back(FlameThrower(this->data->assets.getTexture("Tower3"), this->data->assets.getTexture("Projectile3"), towerArr[i].getPosition()));
							towerArr[2].setPosition(560, 218);
							//towerArr[2].setPosition(580 * (1.0 * this->data->window.getSize().x / SCREEN_WIDTH),
								//180 * (1.0 * this->data->window.getSize().y) / SCREEN_HEIGHT);
						}
						else {
							std::cout << "not enough swats, swat some more" << std::endl;
						}
						break;
					case 3:
						if (mMoney >= ZAPPER_PRICE) {
							mMoney -= ZAPPER_PRICE;
							this->data->turretVector.push_back(Zapper(this->data->assets.getTexture("Tower4"), this->data->assets.getTexture("Projectile4"), towerArr[i].getPosition()));
							towerArr[3].setPosition(560, 112);
							//towerArr[3].setPosition(580 * (1.0 * this->data->window.getSize().x / SCREEN_WIDTH),
								//180 * (1.0 * this->data->window.getSize().y) / SCREEN_HEIGHT);
							break;
						}
						else {
							std::cout << "not enough swats, swat some more" << std::endl;
						}
						this->towerArr[i].setColor(sf::Color(255, 255, 255, 255));
					}
				}
			}
		}
	}
}

bool GameState::isGameOver()
{
	if (playerLives < 1) return true;
	else return false;
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
			//this keep the level clea
			float time = 0.0;
			time = this->clock.getElapsedTime().asSeconds();
			int castTime = time;
			if (castTime %= 20) {
				towerArr[0].setPosition(560, 320);
				towerArr[1].setPosition(560, 428);
				towerArr[2].setPosition(560, 218);
				towerArr[3].setPosition(560, 112);
				std::cout << "CastTime:" << castTime << std::endl;
			}
		}
	}
	
	if (!isGameOver()) {
		cur_round->fetchEnemy(this->data->assets, time, this->data->enemyVector, *testMap->getPath(), round);

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

		for (int i = 0; i < data->turretVector.size(); ++i)
		{
			data->turretVector.at(i).update(data->enemyVector, data->projectileVector);
		}
		for (int i = 0; i < data->projectileVector.size(); ++i)
		{
			if (data->projectileVector.at(i).update(data->enemyVector, data->projectileVector)) {
				data->projectileVector.erase(data->projectileVector.begin() + i);
			}
		}
	}
	else {
		this->data->machine.AddState(StateRef(new EndState(this->data)), true);
	}
}