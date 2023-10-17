#pragma once

#include "Game.h"

#include <SFML/Graphics.hpp>

#include <vector>

#include "Obstacle.h"

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

		const std::vector<sf::Sprite> &LoadSprites() const;
		std::vector<sf::Sprite> &InitPointImg();

	private:
		game_data_ref gameData;
		std::vector<sf::Sprite> pipeImg;
		std::vector<sf::Sprite> scoringPipes;

		int ground_vert;
		int pipe_spawn_yaxis;
	};
}