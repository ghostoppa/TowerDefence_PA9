#pragma once

#include <sstream>
#include <SFML/Graphics.hpp>
#include "Definitions.hpp"
#include "State.hpp"
//#include "GameState.hpp"
#include "GameClassWip.hpp"

class GameState;

class MainMenuState : public State
{
public:
	MainMenuState(GameDataRef data);

	void Init();

	void HandleInput();
	void Update();
	void Draw();


	const int getState()
	{
		return 2;
	}

private:
	GameDataRef data;

	sf::Sprite background;
	sf::Sprite loadGameButton;
	sf::Sprite playGameButton;
};