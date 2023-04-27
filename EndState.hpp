#pragma once
#include <sstream>
#include <SFML/Graphics.hpp>
#include "GameClassWip.hpp"

class GameState;

class EndState : public State
{
public:
	EndState(GameDataRef ref) : data(ref)
	{
		EndText = nullptr;
		debugRoundsText = nullptr;
		mMoney = 0;
		round = 0;
	};


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

