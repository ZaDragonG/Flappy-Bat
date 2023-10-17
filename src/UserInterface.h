#pragma once

#include "DEFINE.h"
#include "Game.h"

#include <SFML/Graphics.hpp>

namespace FlappyBat
{
	class UserInterface
	{
	public:
		UserInterface(game_data_ref data);
		~UserInterface();

		void Render();
		void RefreshScore(int score);

	private:
		game_data_ref gameData;

		sf::Text pointText;
	};
}