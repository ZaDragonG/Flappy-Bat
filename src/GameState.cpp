#pragma once

#include "DEFINITIONS.h"
#include "GameState.h"
#include "GameOverState.h"

#include <iostream>
#include <sstream>

namespace FlappyBat
{
	GameState::GameState(game_data_ref data) : gameData(data)
	{
	}

	void GameState::Init()
	{
		if (!hit_buffer.loadFromFile(HIT_AUDIO))
		{
			std::cout << "Error Loading Hit Sound Effect" << std::endl;
		}

		if (!wing_buffer.loadFromFile(WING_AUDIO))
		{
			std::cout << "Error Loading Wing Sound Effect" << std::endl;
		}

		if (!point_buffer.loadFromFile(POINT_AUDIO))
		{
			std::cout << "Error Loading Point Sound Effect" << std::endl;
		}

		hit_sound.setBuffer(hit_buffer);
		wing_sound.setBuffer(wing_buffer);
		point_sound.setBuffer(point_buffer);

		this->gameData->resource.VisualLoad("Game Background", BACKGROUND);
		this->gameData->resource.VisualLoad("Pipe Up", UPPER_PIPE);
		this->gameData->resource.VisualLoad("Pipe Down", BOTTOM_PIPE);
		this->gameData->resource.VisualLoad("Land", GROUND);
		this->gameData->resource.VisualLoad("Bird Frame 1", BAT_1);
		this->gameData->resource.VisualLoad("Bird Frame 2", BAT_2);
		this->gameData->resource.VisualLoad("Bird Frame 3", BAT_3);
		this->gameData->resource.VisualLoad("Bird Frame 4", BAT_4);
		this->gameData->resource.VisualLoad("Scoring Pipe", PIPE_SCORE);
		this->gameData->resource.LoadFont("Flappy Font", FLAP_FONT);

		pipe = new Pipe(gameData);
		land = new Land(gameData);
		bat = new Bird(gameData);
		hud = new HUD(gameData);

		landscape.setTexture(this->gameData->resource.GetTexture("Game Background"));

		point = 0;
		hud->RefreshScore(point);

		_gameState = GameStates::eReady;
	}

	void GameState::input_handle()
	{
		sf::Event event;

		while (this->gameData->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->gameData->window.close();
			}

			if (this->gameData->input.IsSpriteClicked(this->landscape, sf::Mouse::Left, this->gameData->window))
			{
				if (GameStates::eGameOver != _gameState)
				{
					_gameState = GameStates::ePlaying;
					bat->BirdJump();

					wing_sound.play();
				}
			}
		}
	}

	void GameState::Refresh(float dt)
	{
		if (GameStates::eGameOver != _gameState)
		{
			bat->Animation(dt);
			land->MoveLand(dt);
		}

		if (GameStates::ePlaying == _gameState)
		{
			pipe->pipe_movement(dt);

			if (clock.getElapsedTime().asSeconds() > PIPE_AMOUNT)
			{
				pipe->random_pipe_spawn();

				pipe->imaginary_pipe();
				pipe->bot_pipe();
				pipe->top_pipe();
				pipe->pipe_scoring();

				clock.restart();
			}

			bat->Refresh(dt);

			std::vector<sf::Sprite> landSprites = land->GetSprites();

			for (int i = 0; i < landSprites.size(); i++)
			{
				if (collision.check_collision(bat->GetSprite(), 0.7f, landSprites.at(i), 1.0f))
				{
					_gameState = GameStates::eGameOver;

					clock.restart();

					hit_sound.play();
				}
			}

			std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();

			for (int i = 0; i < pipeSprites.size(); i++)
			{
				if (collision.check_collision(bat->GetSprite(), 0.625f, pipeSprites.at(i), 1.0f))
				{
					_gameState = GameStates::eGameOver;

					clock.restart();

					hit_sound.play();
				}
			}

			if (GameStates::ePlaying == _gameState)
			{
				std::vector<sf::Sprite> &scoringSprites = pipe->GetScoringSprites();

				for (int i = 0; i < scoringSprites.size(); i++)
				{
					if (collision.check_collision(bat->GetSprite(), 0.625f, scoringSprites.at(i), 1.0f))
					{
						point++;

						hud->RefreshScore(point);

						scoringSprites.erase(scoringSprites.begin() + i);

						point_sound.play();
					}
				}
			}
		}

		if (GameStates::eGameOver == _gameState)
		{
			this->gameData->unit.add_state(StateRef(new GameOverState(gameData, point)), true);
		}
	}

	void GameState::Render(float dt)
	{
		this->gameData->window.clear(sf::Color::Red);

		this->gameData->window.draw(this->landscape);

		pipe->RenderPipes();
		land->RenderLand();
		bat->Render();

		hud->Render();

		this->gameData->window.display();
	}
}