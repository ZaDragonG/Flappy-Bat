#pragma once

#include "DEFINITIONS.h"
#include "Game.h"

#include <SFML/Graphics.hpp>

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