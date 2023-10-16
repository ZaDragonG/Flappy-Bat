#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.h"
#include "Game.h"

#include <vector>

namespace Sonar
{
	class Bird
	{
	public:
		Bird(game_data_ref data);
		~Bird();

		void Render();

		void Animation(float dt);

		void Refresh(float dt);

		void BirdJump();

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
