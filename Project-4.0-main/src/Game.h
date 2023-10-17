#pragma once

#include "StateHandler.h"
#include "Assets.h"
#include "ButtonInputs.h"

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>

namespace FlappyBat
{
	struct GameData
	{
		StateHandler unit;
		sf::RenderWindow window;
		Assets resource;
		ButtonInputs input;
	};

	typedef std::shared_ptr<GameData> game_data_ref;

	class Game
	{
	public:
		Game(int width, int height, std::string title);

	private:
		// Updates run at 60 per second.
		const float dt = 1.0f / 60.0f;
		sf::Clock _time;

		game_data_ref gameData = std::make_shared<GameData>();

		void Start();
	};
}