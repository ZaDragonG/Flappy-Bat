#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

namespace FlappyBat
{
	struct GameData
	{
		StateMachine unit;
		sf::RenderWindow window;
		AssetManager resource;
		InputManager input;
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