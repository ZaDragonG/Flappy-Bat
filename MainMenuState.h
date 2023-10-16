#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace Sonar
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