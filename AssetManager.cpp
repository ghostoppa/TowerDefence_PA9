#include "AssetManager.hpp"

void AssetManager::loadTexture(string name, string fileName)
{
	sf::Texture localTexan;

	if (localTexan.loadFromFile(fileName))
	{
		this->textures[name] = localTexan;
	}
	else
	{
		throw FileLoadError();
	}
}

sf::Texture& AssetManager::getTexture(string name)
{
	return this->textures.at(name);
}

void AssetManager::loadFont(string name, string fileName)
{
	sf::Font localFlordian;

	if (localFlordian.loadFromFile(fileName))
	{
		this->fonts[name] = localFlordian;
	}
	else
	{
	throw FileLoadError();
	}
}

sf::Font& AssetManager::getFont(string name)
{
	return this->fonts.at(name);
}

void AssetManager::loadSound(string name, string fileName)
{
	sf::SoundBuffer buffer;

	if (buffer.loadFromFile(fileName))
	{
		sf::Sound localMusican;
		localMusican.setBuffer(buffer);
		this->sounds[name] = localMusican;
	}
	else
	{
		throw FileLoadError();
	}
}

sf::Sound& AssetManager::GetSound(string name)
{
	return this->sounds.at(name);
}
