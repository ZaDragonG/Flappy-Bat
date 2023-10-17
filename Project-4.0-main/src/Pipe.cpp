#include "DEFINE.h"
#include "Pipe.h"

#include <iostream>

namespace FlappyBat
{
	Pipe::Pipe(game_data_ref data) : gameData(data)
	{
		ground_vert = this->gameData->resource.ObtainVisuals("Land").getSize().y;
		pipe_spawn_yaxis = 0;
	}

	void Pipe::bot_pipe()
	{
		sf::Sprite sprite(this->gameData->resource.ObtainVisuals("Upper Pipe"));

		sprite.setPosition(this->gameData->window.getSize().x, this->gameData->window.getSize().y - sprite.getLocalBounds().height - pipe_spawn_yaxis);

		pipeImg.push_back(sprite);
	}

	void Pipe::top_pipe()
	{
		sf::Sprite sprite(this->gameData->resource.ObtainVisuals("Lower Pipe"));

		sprite.setPosition(this->gameData->window.getSize().x, -pipe_spawn_yaxis);

		pipeImg.push_back(sprite);
	}

	void Pipe::imaginary_pipe()
	{
		sf::Sprite sprite(this->gameData->resource.ObtainVisuals("Lower Pipe"));

		sprite.setPosition(this->gameData->window.getSize().x, -pipe_spawn_yaxis);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		pipeImg.push_back(sprite);
	}

	void Pipe::pipe_scoring()
	{
		sf::Sprite sprite(this->gameData->resource.ObtainVisuals("Pipe Point"));

		sprite.setPosition(this->gameData->window.getSize().x, 0);

		scoringPipes.push_back(sprite);
	}

	void Pipe::pipe_movement(float dt)
	{
		for (long unsigned int i = 0; i < pipeImg.size(); i++)
		{
			if (pipeImg.at(i).getPosition().x < 0 - pipeImg.at(i).getLocalBounds().width)
			{
				pipeImg.erase(pipeImg.begin() + i);
			}
			else
			{
				sf::Vector2f position = pipeImg.at(i).getPosition();
				float move = PIPE_SPEED * dt;

				pipeImg.at(i).move(-move, 0);
			}
		}

		for (long unsigned int i = 0; i < scoringPipes.size(); i++)
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
		for (unsigned short int i = 0; i < pipeImg.size(); i++)
		{
			this->gameData->window.draw(pipeImg.at(i));
		}
	}

	void Pipe::random_pipe_spawn()
	{
		pipe_spawn_yaxis = rand() % (ground_vert + 1);
	}

	const std::vector<sf::Sprite> &Pipe::LoadSprites() const
	{
		return pipeImg;
	}

	std::vector<sf::Sprite> &Pipe::InitPointImg()
	{
		return scoringPipes;
	}
}