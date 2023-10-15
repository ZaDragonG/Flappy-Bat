#include <SFML/Graphics.hpp>
#include "AssetManager.h"

namespace FlappyBat
{
	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture texture;

		if (texture.loadFromFile(fileName))
		{
			this->_textures[name] = texture;
		}
	}

	sf::Texture &AssetManager::GetTexture(std::string name)
	{
		return this->_textures.at(name);
	}

	void AssetManager::LoadFont(std::string name, std::string fileName)
	{
		sf::Font type;

		if (type.loadFromFile(fileName))
		{
			this->_fonts[name] = type;
		}
	}

	sf::Font &AssetManager::GetFont(std::string name)
	{
		return this->_fonts.at(name);
	}
}
