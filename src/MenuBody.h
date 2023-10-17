#pragma once

#include "Game.h"
#include "Virtual.h"

#include <SFML/Graphics.hpp>

namespace FlappyBat
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(game_data_ref data);

		void Init();

		void input_handle();
		void Refresh(float dt);
		void Render(float dt);

	private:
		game_data_ref gameData;

		sf::Sprite landscape;
		sf::Sprite name;
		sf::Sprite play_switch;
	};
}