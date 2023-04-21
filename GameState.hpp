#pragma once

#include <sstream>
#include <SFML/Graphics.hpp>
#include "Definitions.hpp"
#include "State.hpp"
#include "GameClassWip.hpp"

class   GameState : State
{
public:
	GameState(GameDataRef data);

	void Init();

	void HandleInput();
	void Update();
	void Draw();

private:
	GameDataRef data;

	sf::Sprite tower1;
	sf::Sprite tower2;
	sf::Sprite tower3;
	sf::Sprite tower4;
	sf::Sprite tower5;
	sf::Sprite tower6;

};

