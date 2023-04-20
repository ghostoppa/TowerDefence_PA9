#include "GameClassWip.hpp"
#include "SplashState.hpp"
GameWip::GameWip(int width, int hight, std::string title)
{
	data->window.create(sf::VideoMode(width, hight), title,
		sf::Style::Close | sf::Style::Titlebar);
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
		}
	}
}
