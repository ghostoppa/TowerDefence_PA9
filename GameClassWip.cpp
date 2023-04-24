#include "GameClassWip.hpp"
#include "SplashState.hpp"
GameWip::GameWip(int width, int height, std::string title)
{
	data->window.create(sf::VideoMode(width, height), title,
		sf::Style::Close | sf::Style::Titlebar);
	data->window.setFramerateLimit(60);
	data->machine.AddState(StateRef(new SplashState(this->data)));
	this->Run();
}


void GameWip::Run()
{
	
		while (this->data->window.isOpen())
		{
			while (this->data->window.isOpen())
			{
				this->data->machine.ProcessStateChanges();
				this->data->machine.GetActiveState()->HandleInput();
				
				this->data->machine.GetActiveState()->Draw();
				this->data->machine.GetActiveState()->Update();

			}
		}
}
