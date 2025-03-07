#pragma once

#include "DEFINE.h"
#include "Game.h"

#include <SFML/Graphics.hpp>

#include <vector>

namespace FlappyBat
{
	class Bat
	{
	public:
		Bat(game_data_ref data);
		~Bat();

		void Render();

		void Animation(float dt);

		void Refresh(float dt);

		void BatJump();

		const sf::Sprite &GetSprite() const;

	private:
		game_data_ref gameData;

		sf::Sprite bat_sprite;
		std::vector<sf::Texture> anime_frame;

		unsigned int animation_change;

		sf::Clock _time;

		sf::Clock movement_clock;

		int bat_state;

		float bat_rotate;
	};
}
