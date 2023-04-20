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
	float newTime = 0, frameTime = 0, interpolations = 0;
	float currentTime = this->clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;
	while (this->data->window.isOpen())
	{
		while (this->data->window.isOpen())
		{
			this->data->machine.ProcessStateChanges();
			newTime = this->clock.getElapsedTime().asSeconds();

			frameTime = newTime - currentTime;
			if (frameTime > .25f)
			{
				frameTime = .25f;
			}
			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->data->machine.GetActiveState()->HandleInput();
				this->data->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}
			interpolations = accumulator / dt;
			this->data->machine.GetActiveState()->Draw(interpolations);
		}
	}
}
