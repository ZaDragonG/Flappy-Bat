#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "DEFINITIONS.h"

namespace Sonar
{
	class Flash
	{
	public:
		Flash(game_data_ref data);
		~Flash();

		void Display(float dt);
		void Render();

	private:
		game_data_ref gameData;

		sf::RectangleShape structure;

		bool flash_on;

	};
}
