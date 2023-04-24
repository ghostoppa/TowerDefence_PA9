#include "MainMenuState.h"
#include <iostream>
MainMenuState::MainMenuState(GameDataRef data) : data(data)
{}

void MainMenuState::Init()
{
		this->data->curSound.stop();
	
	this->data->curSound.openFromFile(menuSound);
	this->data->curSound.play();
	this->data->curSound.setLoop(true);
	try {
		this->data->assets.loadTexture("Background", MENU_BG);
		this->data->assets.loadTexture("Play", PLAY_BTN);
		this->data->assets.loadTexture("Load", LOAD_BTN);

		this->background.setTexture(this->data->assets.getTexture("Background"));
		this->loadGameButton.setTexture(this->data->assets.getTexture("Load"));
		this->playGameButton.setTexture(this->data->assets.getTexture("Play"));

		this->playGameButton.setPosition(
			SCREEN_WIDTH / 2 - this->playGameButton.getGlobalBounds().width / 4,
			SCREEN_HEIGHT / 2 - this->playGameButton.getGlobalBounds().height / 3);

		this->loadGameButton.setPosition(
			SCREEN_WIDTH / 2 - this->loadGameButton.getGlobalBounds().width / 2,
			SCREEN_HEIGHT / 2 - this->loadGameButton.getGlobalBounds().height *2);
	}
	catch (FileLoadError &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void MainMenuState::HandleInput()
{
	sf::Event event;

	while (this->data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->data->window.close();
		}
		if (this->data->inputs.IsSpriteClicked(this->playGameButton,
			sf::Mouse::Left, this->data->window))
		{
			this->data->machine.AddState(StateRef(new GameState(this->data)), true);

		}

	}
}

		
void MainMenuState::Update()
{
	if (!(this->data->curSound.Playing==2))	{
		this->data->curSound.openFromFile(menuSound);
		this->data->curSound.play();
	}
}

void MainMenuState::Draw()
{
	this->data->window.clear();
	this->data->window.draw(this->background);
	this->data->window.draw(this->loadGameButton);
	this->data->window.draw(this->playGameButton);
	this->data->window.display();
}