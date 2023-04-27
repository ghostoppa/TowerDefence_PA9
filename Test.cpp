#include "Test.hpp"




Test::Test()
{
	int choice = 0;
	std::cout << "Please Make a selection of which test to preform" << std::endl;
	std::cout << "Option 1: splash state test" << std::endl;
	std::cout << "Option 2: menu state button test" << std::endl;
	std::cout << "option 3: game transiton test" << std::endl;
	std::cout << "Option 4: AssetManagerTest" << std::endl;
	std::cout << "Option 5: Input Manager Test" << std::endl;
	while (choice > 5 || choice < 1)
	{
		std::cout << "Please Make a selection 1-5 of which test to preform" << std::endl;
		std::cin >> choice;
	}

	switch (choice)
	{
	case 1:
		splashStateTransTest();
		break;
	case 2:
		menuStateTransTest();
		break;
	case 3:
		gameTransTest();
		break;
	case 4:
		AssetManagerTest();
		break;
	case 5:
		InputManagerTest();
		break;

	}
}

void Test::splashStateTransTest()
{
	sf::Clock newClock;
	bool sentMessege = false;
	GameDataRef data = std::make_shared<GameData>();
	data->window.create(sf::VideoMode(640, 480), "Splash Transition Test",
		sf::Style::Close | sf::Style::Titlebar);
	data->window.setFramerateLimit(12);
	std::cout << "POPING EMPTY STATE MACHINE" << std::endl;
	std::cout << "ADDING SPLASH STATE" << std::endl;
	data->machine.AddState(StateRef(new SplashState(data)), false);
	while (data->window.isOpen() && newClock.getElapsedTime().asSeconds() <= 4)
	{


		data->machine.ProcessStateChanges();

		data->machine.GetActiveState()->Update();
		data->machine.GetActiveState()->Draw();
		if (data->machine.GetActiveState()->getState()== 2&&!sentMessege)
		{
			sentMessege = true;
			std::cout << "Spash switch to Menu" << std::endl;
		}
	}
	data->machine.RemoveState();
	

	

	

}

void Test::menuStateTransTest()
{
	sf::Clock newClock;
	bool sentMessege = false;
	GameDataRef data = std::make_shared<GameData>();
	data->window.create(sf::VideoMode(640, 480), "Menu Button TEST",
		sf::Style::Close | sf::Style::Titlebar);
	data->window.setFramerateLimit(12);
	std::cout << "PLEASE PRESS THE LOAD BUTTON TO TEST FUNCTIONALITY" << std::endl;
	std::cout << "ADDING MENU STATE" << std::endl;
	data->machine.AddState(StateRef(new MainMenuState(data)), true);
	while (data->window.isOpen() && newClock.getElapsedTime().asSeconds() <= 10)
	{


		data->machine.ProcessStateChanges();

		data->machine.GetActiveState()->Update();
		data->machine.GetActiveState()->Draw();
		data->machine.GetActiveState()->HandleInput();
		if (data->machine.GetActiveState()->getState() == 3&&!sentMessege)
		{
			sentMessege = true;
			std::cout << "MENU BUTTON SUCCESFULLY PUSHED" << std::endl;
		}
	}
	data->machine.~StateMachine();

}

void Test::gameTransTest()
{
	
		sf::Clock newClock;
		bool sentMessege = false;
		GameDataRef data = std::make_shared<GameData>();
		data->window.create(sf::VideoMode(640, 480), " Game transition Test",
			sf::Style::Close | sf::Style::Titlebar);
		data->window.setFramerateLimit(12);
		std::cout << "ADDING GAME STATE" << std::endl;
		data->machine.AddState(StateRef(new GameState(data)), true);
		while (data->window.isOpen() && newClock.getElapsedTime().asSeconds() <= 300)
		{


			data->machine.ProcessStateChanges();

			data->machine.GetActiveState()->Update();
			data->machine.GetActiveState()->Draw();
			if (data->machine.GetActiveState()->getState() == 4 && !sentMessege)
			{
				sentMessege = true;
				std::cout << "GAME TO END SUCCESS!!" << std::endl;
			}
		}
		
	}

void Test::AssetManagerTest()
{
	int option = 0;
	sf::Clock newClock;
	AssetManager newAssetManager;
	sf::RenderWindow newWindow;
	newWindow.create(sf::VideoMode(1920, 1080), "AssetTest",
		sf::Style::Close | sf::Style::Titlebar);
	newWindow.setFramerateLimit(12);
	try {
		newAssetManager.loadFont("testFont", "assets/fonts/Open 24 Display St.ttf");
		newAssetManager.loadSound("testSound", TESTSOUND);
		newAssetManager.loadTexture("testTexture",TESTTEXTURE );
		sf::Text text("SUCCESS FONT TEST", newAssetManager.getFont("testFont"), 100);
		text.setFillColor(sf::Color::Red);
		text.setPosition(700, 540);

		sf::Sprite textSprite(newAssetManager.getTexture("testTexture"));
		
		
		sf::SoundBuffer f;
		f.loadFromFile(TESTSOUND);
		sf::Sound fd;
		fd.setBuffer(f);
			newWindow.draw(textSprite);
		newWindow.draw(text);
		newWindow.display();
	fd.play();

		while (newClock.getElapsedTime().asSeconds() <= 10);
	
	}
	catch (FileLoadError& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "NON-ASSET MANAGER RELATED FAILURE" << std::endl;
	}
}


void Test::InputManagerTest()
{

	sf::Clock newClock;
	bool sentMessege = false;
	GameDataRef data = std::make_shared<GameData>();
	data->window.create(sf::VideoMode(640, 480), "Menu Button TEST",
		sf::Style::Close | sf::Style::Titlebar);
	data->machine.AddState(StateRef(new InputTest(data)), false);
	while (data->window.isOpen())
	{


		data->machine.ProcessStateChanges();

		data->machine.GetActiveState()->Update();
		data->machine.GetActiveState()->Draw();
		data->machine.GetActiveState()->HandleInput();
		if (data->machine.GetActiveState()->getState() == 3 && !sentMessege)
		{
			data->window.close();
				}
	}


}


