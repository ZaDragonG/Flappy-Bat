#pragma once

#include "Virtual.h"
#include "Game.h"

#include <SFML/Graphics.hpp>

namespace FlappyBat
{
	class BackgroundImg : public State
	{
	public:
		BackgroundImg(game_data_ref data);

		void SetGameElements();

		void input_handle();
		void Refresh(float dt);
		void Render(float dt);

	private:
		game_data_ref gameData;

		sf::Clock _time;

		sf::Sprite landscape;
	};
}