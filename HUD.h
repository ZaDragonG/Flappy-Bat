#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.h"
#include "Game.h"

namespace FlappyBat
{
	class HUD
	{
	public:
		HUD(game_data_ref data);
		~HUD();

		void Render();
		void RefreshScore(int score);

	private:
		game_data_ref gameData;

		sf::Text pointText;

	};
}