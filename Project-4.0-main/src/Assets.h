#pragma once

#include <SFML/Graphics.hpp>

#include <map>

namespace FlappyBat
{
	class Assets
	{
	public:
		Assets() {}
		~Assets() {}

		void VisualLoad(std::string name, std::string fileName);
		sf::Texture &ObtainVisuals(std::string name);

		void TextTypeLoad(std::string name, std::string fileName);
		sf::Font &ObtainText(std::string name);

	private:
		std::map<std::string, sf::Texture> textures;
		std::map<std::string, sf::Font> fonts;
	};
}
