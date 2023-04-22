#include "SplashState.hpp"
#include <iostream>
SplashState::SplashState(GameDataRef data) :data(data)
{
}

void SplashState::Init()
{
	try {
		this->data->assets.loadTexture("bad", SPLASH);
		this->background.setTexture(this->data->assets.getTexture("bad"));
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


void SplashState::Update()
{
	if (this->clock.getElapsedTime().asSeconds() > 3)
	{
		this->data->machine.AddState(StateRef(new MainMenuState(this->data)), true);
		//this->data->machine.ProcessStateChanges();
		
	}
}

void SplashState::Draw()
{
	this->data->window.clear(sf::Color::Magenta);

	this->data->window.draw(this->background);

	this->data->window.display();
}
