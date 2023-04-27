#pragma once
#include <sstream>
#include <SFML/Graphics.hpp>
#include "GameClassWip.hpp"


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
	const int getState()
	{
		return 4;
	}

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

