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

	void LoadTexture(string name, string fileName);
	sf::Texture& GetTexture(string name);

	void LoadFont(string name, string fileName);
	sf::Font& GetFont(string name);

	void LoadSound(string name, string fileName);
	sf::Sound& GetSounce(string name);
	
private:
	std::map<string, sf::Texture> textures;
	std::map<string, sf::Font> fonts;
	std::map<string, sf::Sound> sounds;

};
