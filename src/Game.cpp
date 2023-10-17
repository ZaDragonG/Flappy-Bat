#include "Game.h"
#include "BackgroundImg.h"

#include <stdlib.h>
#include <time.h>

namespace FlappyBat
{
	Game::Game(int width, int height, std::string title)
	{
		srand(time(NULL));

		gameData->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		gameData->unit.add_state(StateRef(new BackgroundImg(this->gameData)));

		this->Start();
	}

	void Game::Start()
	{
		float new_clock, time_frame, inter;

		float current_clock = this->_time.getElapsedTime().asSeconds();
		float accumulate = 0.0f;

		while (this->gameData->window.isOpen())
		{
			this->gameData->unit.state_change();

			new_clock = this->_time.getElapsedTime().asSeconds();
			time_frame = new_clock - current_clock;

			if (time_frame > 0.25f)
			{
				time_frame = 0.25f;
			}

			current_clock = new_clock;
			accumulate += time_frame;

			while (accumulate >= dt)
			{
				this->gameData->unit.active_state()->input_handle();
				this->gameData->unit.active_state()->Refresh(dt);

				accumulate -= dt;
			}

			inter = accumulate / dt;
			this->gameData->unit.active_state()->Render(inter);
		}
	}
}