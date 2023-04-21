#include "MainMenuState.h"
#include <iostream>
MainMenuState::MainMenuState(GameDataRef data) : data(data)
{}

void MainMenuState::Init()
{
	try {
		this->data->assets.loadTexture("Background", "assets/img/MenuBackGroundPlaceHolder.png");
		this->data->assets.loadTexture("Play", "assets/img/PlayPlaceHolder.png");
		this->data->assets.loadTexture("Load", "assets/img/LoadPlaceHolder.png");

		this->background.setTexture(this->data->assets.getTexture("Background"));
		this->loadGameButton.setTexture(this->data->assets.getTexture("Load"));
		this->playGameButton.setTexture(this->data->assets.getTexture("Play"));

		this->playGameButton.setPosition(
			SCREEN_WIDTH / 2 - this->playGameButton.getGlobalBounds().width / 2,
			SCREEN_HEIGHT / 2 - this->playGameButton.getGlobalBounds().height / 2);

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
			std::cout << "This will be the game screen transition" << std::endl;
		}

	}
}

		
void MainMenuState::Update()
{

}

void MainMenuState::Draw()
{
	this->data->window.clear();
	this->data->window.draw(this->background);
	this->data->window.draw(this->loadGameButton);
	this->data->window.draw(this->playGameButton);
	this->data->window.display();
}