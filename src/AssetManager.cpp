#include "AssetManager.h"

#include <SFML/Graphics.hpp>

namespace FlappyBat
{
	void AssetManager::VisualLoad(std::string name, std::string fileName)
	{
		sf::Texture texture;

		if (texture.loadFromFile(fileName))
		{
			this->textures[name] = texture;
		}
	}

	sf::Texture &AssetManager::GetTexture(std::string name)
	{
		return this->textures.at(name);
	}

	void AssetManager::LoadFont(std::string name, std::string fileName)
	{
		sf::Font type;

		if (type.loadFromFile(fileName))
		{
			this->fonts[name] = type;
		}
	}

	sf::Font &AssetManager::GetFont(std::string name)
	{
		return this->fonts.at(name);
	}
}
