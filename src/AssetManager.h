#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace FlappyBat
{
	class AssetManager
	{
	public:
		AssetManager() { }
		~AssetManager() { }

		void VisualLoad(std::string name, std::string fileName);
		sf::Texture &GetTexture(std::string name);

		void LoadFont(std::string name, std::string fileName);
		sf::Font &GetFont(std::string name);

	private:
		std::map<std::string, sf::Texture> textures;
		std::map<std::string, sf::Font> fonts;
	};
}
