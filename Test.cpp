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
	sf::Clock newClock;
	AssetManager newAssetManager;
	sf::RenderWindow newWindow;
	newWindow.create(sf::VideoMode(1920, 1080), "AssetTest",
		sf::Style::Close | sf::Style::Titlebar);
	newWindow.setFramerateLimit(60);

	try {
		newAssetManager.loadFont("testFont", "assets/fonts/Open 24 Display St.ttf");
		newAssetManager.loadSound("testSound", menuSound);
		newAssetManager.loadTexture("testTexture", MENUBACKGROUND);
		sf::Text text("SUCCESS FONT TEST", newAssetManager.getFont("testFont"), 40);
		text.setPosition(900, 540);

		sf::Sprite textSprite(newAssetManager.getTexture("testTexture"));
		
			

		newAssetManager.getSound("testSound");

			newWindow.draw(textSprite);
		newWindow.draw(text);
		newWindow.display();
		newAssetManager.getSound("testSound").play();

		while (newClock.getElapsedTime().asSeconds() <50) {

		}
		newWindow.close();

	}
	catch (FileLoadError& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "NON-ASSET MANAGER RELATED FAILURE" << std::endl;
	}
}

