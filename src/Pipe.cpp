#include "Pipe.h"
#include "DEFINITIONS.h"

#include <iostream>

namespace FlappyBat
{
	Pipe::Pipe(game_data_ref data) : gameData(data)
	{
		ground_vert = this->gameData->resource.GetTexture("Land").getSize().y;
		pipe_spawn_yaxis = 0;
	}

	void Pipe::bot_pipe()
	{
		sf::Sprite sprite(this->gameData->resource.GetTexture("Pipe Up"));

		sprite.setPosition(this->gameData->window.getSize().x, this->gameData->window.getSize().y - sprite.getLocalBounds().height - pipe_spawn_yaxis);

		pipeSprites.push_back(sprite);
	}

	void Pipe::top_pipe()
	{
		sf::Sprite sprite(this->gameData->resource.GetTexture("Pipe Down"));

		sprite.setPosition(this->gameData->window.getSize().x, -pipe_spawn_yaxis);

		pipeSprites.push_back(sprite);
	}

	void Pipe::imaginary_pipe()
	{
		sf::Sprite sprite(this->gameData->resource.GetTexture("Pipe Down"));

		sprite.setPosition(this->gameData->window.getSize().x, -pipe_spawn_yaxis);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		pipeSprites.push_back(sprite);
	}

	void Pipe::pipe_scoring()
	{
		sf::Sprite sprite(this->gameData->resource.GetTexture("Scoring Pipe"));

		sprite.setPosition(this->gameData->window.getSize().x, 0);

		scoringPipes.push_back(sprite);
	}

	void Pipe::pipe_movement(float dt)
	{
		for ( int i = 0; i < pipeSprites.size(); i++)
		{
			if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getLocalBounds().width)
			{
				pipeSprites.erase( pipeSprites.begin( ) + i );
			}
			else
			{
				sf::Vector2f position = pipeSprites.at(i).getPosition();
				float move = PIPE_SPEED * dt;

				pipeSprites.at(i).move(-move, 0);
			}
		}

		for (int i = 0; i < scoringPipes.size(); i++)
		{
			if (scoringPipes.at(i).getPosition().x < 0 - scoringPipes.at(i).getLocalBounds().width)
			{
				scoringPipes.erase(scoringPipes.begin() + i);
			}
			else
			{
				sf::Vector2f position = scoringPipes.at(i).getPosition();
				float move = PIPE_SPEED * dt;

				scoringPipes.at(i).move(-move, 0);
			}
		}
	}

	void Pipe::RenderPipes()
	{
		for (unsigned short int i = 0; i < pipeSprites.size(); i++)
		{
			this->gameData->window.draw(pipeSprites.at(i));
		}
	}

	void Pipe::random_pipe_spawn()
	{
		pipe_spawn_yaxis = rand() % (ground_vert + 1);
	}

	const std::vector<sf::Sprite> &Pipe::GetSprites() const
	{
		return pipeSprites;
	}

	std::vector<sf::Sprite> &Pipe::GetScoringSprites()
	{
		return scoringPipes;
	}
}