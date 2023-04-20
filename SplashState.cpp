#include "SplashState.hpp"
#include <iostream>
SplashState::SplashState(GameDataRef data) :data(data)
{
}

void SplashState::Init()
{
	try {
		this->data->assets.loadTexture("map1", "assets/img/map1.png");
		this->background.setTexture(this->data->assets.getTexture("map1"));
	}
	catch (FileLoadError e)
	{
		std::cout <<e.what() << std::endl;
	}
}
	
void SplashState::HandleInput()
	{
	sf::Event event;

		while (this->data->window.pollEvent( event) )
		{
			if (sf::Event::Closed == event.type)
			{
				this->data->window.close();
			}
	}
}


void SplashState::Update(float dt)
{
	if (this->clock.getElapsedTime().asSeconds() > 3)
	{
	}

}

void SplashState::Draw(float dt)
{
	this->data->window.clear(sf::Color::Magenta);

	this->data->window.draw(this->background);

	this->data->window.display();
}
