#pragma once

#include <sstream>
#include <SFML/Graphics.hpp>
#include "Definitions.hpp"
#include "State.hpp"
#include "GameClassWip.hpp"

class   MainMenuState : public State
{
public:
	MainMenuState(GameDataRef data);

	void Init();

	void HandleInput();
	void Update();
	void Draw();

private:
	GameDataRef data;

	sf::Sprite background;
	sf::Sprite loadGameButton;
	sf::Sprite playGameButton;
	//more to be implimented


};

