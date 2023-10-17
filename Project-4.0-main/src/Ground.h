#pragma once

#include "Game.h"

#include <SFML/Graphics.hpp>

#include <vector>

namespace FlappyBat
{
	class Ground
	{
	public:
		Ground(game_data_ref data);

		void MoveGround(float dt);
		void RenderGround();

		const std::vector<sf::Sprite> &LoadSprites() const;

	private:
		game_data_ref gameData;

		std::vector<sf::Sprite> ground_sprite;
	};
}