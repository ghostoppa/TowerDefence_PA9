#include "EndState.hpp"



EndState::EndState(GameDataRef ref){
	
			data = ref;
	
}

void EndState::Init()
{
	debugRoundsText = new sf::Text(("You Died: \nLets Play Again"), data->assets.getFont("roboto"), 30);
	EndText = new sf::Text("Made By: \nZachary Johnston\n Lilith Sutton\nLily Ollerman\n Dante" , data->assets.getFont("roboto"), 40);
	this->debugRoundsText->setPosition(this->data->window.getSize().x/5.0, this->data->window.getSize().y *.1);
	this->EndText->setPosition(this->data->window.getSize().x / 3.0, this->data->window.getSize().y * .3);
	EndText->setFillColor(sf::Color(92, 25, 71, 255));
	debugRoundsText->setFillColor(sf::Color::Red);

	this->background.setTexture(data->assets.getTexture("splashbackground"));
}

void EndState::HandleInput()
{
	sf::Event event;

	while (this->data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->data->window.close();
		}
	}
}

void EndState::Update()
{
	if (this->clock.getElapsedTime().asSeconds() > 30)
	{
		this->data->machine.AddState(StateRef(new MainMenuState(this->data)), true);
		//this->data->machine.ProcessStateChanges();

	}
}

void EndState::Draw()
{
	this->data->window.draw(this->background);
	this->data->window.draw(*debugRoundsText);
	this->data->window.draw(*EndText);
	this->data->window.display();
}
