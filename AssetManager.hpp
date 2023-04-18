#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "FileLoadErrorException.hpp"
using std::string;
class AssetManager
{
public:
	AssetManager() {}
	~AssetManager() {}

	void loadTexture(string name, string fileName);
	sf::Texture& getTexture(string name);

	void loadFont(string name, string fileName);
	sf::Font& getFont(string name);

	void loadSound(string name, string fileName);
	sf::Sound& getSound(string name);
	
private:
	std::map<string, sf::Texture> textures;
	std::map<string, sf::Font> fonts;
	std::map<string, sf::Sound> sounds;

};
