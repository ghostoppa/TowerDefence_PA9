#pragma once
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Definitions.hpp"
#include "State.hpp"
#include "GameClassWip.hpp"

class    EndState: public State
{
public:
	EndState(GameDataRef ref);


	void Init();

	void HandleInput();
	void Update();
	void Draw();


private:

	sf::Font neat;
	GameDataRef data;
	int mMoney;
	int round;
	sf::Clock clock;
	sf::Sprite background;
	sf::Text *EndText;
	sf::Text* debugRoundsText;
};

