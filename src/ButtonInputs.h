#pragma once

#include <SFML/Graphics.hpp>

namespace FlappyBat
{
	class ButtonInputs
	{
	public:
		ButtonInputs() {}
		~ButtonInputs() {}

		bool IsSpriteClicked(sf::Sprite thing, sf::Mouse::Button button, sf::RenderWindow &window);

		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};
}