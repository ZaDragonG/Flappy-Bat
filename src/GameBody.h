#pragma once

#include "Bat.h"
#include "Collision.h"
#include "Game.h"
#include "UserInterface.h"
#include "Ground.h"
#include "Pipe.h"
#include "Virtual.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace FlappyBat
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

		UserInterface *hud;

		sf::Clock clock;

		int _gameState;
		int point;

		sf::SoundBuffer hit_buffer;
		sf::SoundBuffer wing_buffer;
		sf::SoundBuffer point_buffer;

		sf::Sound hit_sound;
		sf::Sound wing_sound;
		sf::Sound point_sound;
	};
}
