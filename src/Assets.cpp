#include "Assets.h"

#include <SFML/Graphics.hpp>

namespace FlappyBat
{
	void Assets::VisualLoad(std::string name, std::string fileName)
	{
		sf::Texture texture;

		if (texture.loadFromFile(fileName))
		{
			this->textures[name] = texture;
		}
	}

	sf::Texture &Assets::ObtainVisuals(std::string name)
	{
		return this->textures.at(name);
	}

	void Assets::LoadFont(std::string name, std::string fileName)
	{
		sf::Font type;

		if (type.loadFromFile(fileName))
		{
			this->fonts[name] = type;
		}
	}

	sf::Font &Assets::ObtainText(std::string name)
	{
		return this->fonts.at(name);
	}
}
