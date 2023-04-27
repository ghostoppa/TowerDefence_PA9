#include "GameClassWip.hpp"
#include "SplashState.hpp"
#include "GameState.hpp"
#include "InputTest.hpp"
/**
Note: The Linear Path has an integrated test that outputs to the consle the result of its input
Note: The Path has an integrated test that outputs to the consle to result of its input



**/
class Test
{
public:
	Test();

		void splashStateTransTest();
		//Note: The MenuStateTransTest Funtion Requires User Input to test the button.
		void menuStateTransTest();

		void gameTransTest();

		
/**	Note: The Asset Test should Present An Image of the Arch Logo with in Black  "SUCCSEFUL TEXTURE ASSET
this Will indiacte the success of the Texture aspect of of AssetManager.A sound should then state
		"This means the test was successful. This will inidcate the succes of sound  asspect of the AssetManager.
		On the ArchLogo there should be in red 8 block text that states "SUCCESS FONT TEST" which will indicate
		the success of the font part of the AssetManager.
		**/
	void AssetManagerTest();

	void InputManagerTest();
	};

