#include "InputTest.hpp"
#include "GameState.hpp"
#include <iostream>
InputTest::InputTest(GameDataRef data) : data(data)
{}

void InputTest::Init()
{
	try {
			this->data->assets.loadTexture("Play", "assets/img/spriteTest.png");
	
			this->playGameButton.setTexture(this->data->assets.getTexture("Play"));

		this->playGameButton.setPosition(
			SCREEN_WIDTH / 2 - this->playGameButton.getGlobalBounds().width / 4 - 15,
			(SCREEN_HEIGHT / 2) + 30);
		//SCREEN_HEIGHT / 2 - this->playGameButton.getGlobalBounds().height / 3);

		}
	catch (FileLoadError& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void InputTest::HandleInput()
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
			std::cout << "BUTTON WAS CLICKED AT: " << sf::Mouse::getPosition().x << "," << sf::Mouse::getPosition().y << std::endl;
		}
	}
}


void InputTest::Update()
{
}

void InputTest::Draw()
{
	this->data->window.clear();
	this->data->window.draw(this->playGameButton);
	this->data->window.display();
}