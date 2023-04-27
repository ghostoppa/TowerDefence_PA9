#pragma once

#include <sstream>
#include <SFML/Graphics.hpp>
#include "Definitions.hpp"
#include "State.hpp"
//#include "GameState.hpp"
#include "GameClassWip.hpp"

class GameState;

class InputTest : public State
{
public:
	InputTest(GameDataRef data);

	void Init();

	void HandleInput();
	void Update();
	void Draw();


	const int getState()
	{
		return -1;
	}

private:
	GameDataRef data;

	sf::Sprite playGameButton;
};