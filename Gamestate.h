#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "State.h"
#include "Game.h"
#include "Pipe.h"
#include "Land.h"
#include "Bird.h"
#include "Collision.h"
#include "Flash.h"
#include "HUD.h"

namespace Sonar
{
	class GameState : public State
	{
	public:
		GameState(game_data_ref data);

		void Init();

		void input_handle();
		void Refresh(float dt);
		void Render(float dt);

	private:
		game_data_ref gameData;

		sf::Sprite landscape;

		Pipe *pipe;
		Land *land;
		Bird *bat;
		Collision collision;
		Flash *flash;
		HUD *hud;

		sf::Clock clock;

		int _gameState;

		sf::RectangleShape _gameOverFlash;
		bool flash_on;

		int point;

		sf::SoundBuffer hit_buffer;
		sf::SoundBuffer wing_buffer;
		sf::SoundBuffer point_buffer;

		sf::Sound hit_sound;
		sf::Sound wing_sound;
		sf::Sound point_sound;

	};
}
