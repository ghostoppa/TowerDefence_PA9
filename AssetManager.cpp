#include "AssetManager.hpp"

void AssetManager::LoadTexture(string name, string fileName)
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

sf::Texture& AssetManager::GetTexture(string name)
{
	return this->textures.at(name);
}

void AssetManager::LoadFont(string name, string fileName)
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

sf::Font& AssetManager::GetFont(string name)
{
	return this->fonts.at(name);
}

void AssetManager::LoadSound(string name, string fileName)
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
