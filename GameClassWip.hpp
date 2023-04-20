#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

typedef struct gameData
{
	StateMachine machine;
	sf::RenderWindow window;
	AssetManager assets;
	InputManager inputs;
}GameData;

typedef std::shared_ptr<GameData> GameDataRef;

class GameWip
{
public:
	GameWip(int width, int hight, std::string title);
	
private:
	GameDataRef data = std::make_shared<GameData>();
	sf::Clock clock;

	const float dt= 1.0f / 60.0f;
	void Run();
};

