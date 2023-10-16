#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

namespace FlappyBat
{
	class Pipe
	{
	public:
		Pipe(game_data_ref data);

		void bot_pipe();
		void top_pipe();
		void imaginary_pipe();
		void pipe_scoring();
		void pipe_movement(float dt);
		void RenderPipes();
		void random_pipe_spawn();

		const std::vector<sf::Sprite> &GetSprites() const;
		std::vector<sf::Sprite> &GetScoringSprites();

	private:
		game_data_ref gameData;
		std::vector<sf::Sprite> pipeSprites;
		std::vector<sf::Sprite> scoringPipes;

		int ground_vert;
		int pipe_spawn_yaxis;

	};
}