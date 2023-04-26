#pragma once
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Definitions.hpp"
#include "State.hpp"
#include "GameClassWip.hpp"
#include "MainMenuState.h"


class  SplashState : public State
{
public:
	SplashState(GameDataRef data);

	void Init();

	void HandleInput();
	void Update();
	void Draw();

private:
	GameDataRef data;
	sf::Clock clock;
	sf::Sprite logo;
	sf::Sprite background;
};
