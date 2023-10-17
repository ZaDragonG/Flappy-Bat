#pragma once

#include <SFML/Graphics.hpp>

namespace FlappyBat
{
	class Collision
	{
	public:
		Collision();
		~Collision();

		bool check_collision(sf::Sprite sprite_1, sf::Sprite sprite_2);
		bool check_collision(sf::Sprite sprite_1, float scale_1, sf::Sprite sprite_2, float scale_2);
	};
}
