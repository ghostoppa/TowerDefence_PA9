#include "Test.hpp"

Test::Test()
{
	int choice = 0;
	std::cout << "Please Make a selection of which test to preform" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;

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

