#pragma once

#include "Game.h"

#include <SFML/Graphics.hpp>

#include <vector>

namespace FlappyBat
{
	class Land
	{
	public:
		Land(game_data_ref data);

		void MoveLand(float dt);
		void RenderLand();

		const std::vector<sf::Sprite> &GetSprites() const;

	private:
		game_data_ref gameData;

		std::vector<sf::Sprite> ground_sprite;
	};
}