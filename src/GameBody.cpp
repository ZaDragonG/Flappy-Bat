#pragma once

#include "DEFINE.h"
#include "GameBody.h"
#include "GameEnd.h"

#include <iostream>
#include <sstream>

namespace FlappyBat
{
	GameBody::GameBody(game_data_ref data) : gameData(data)
	{
	}

	void GameBody::SetGameElements()
	{

		hit_sound.setBuffer(hit_buffer);
		wing_sound.setBuffer(wing_buffer);
		point_sound.setBuffer(point_buffer);

		this->gameData->resource.VisualLoad("LandScape", BACKGROUND);
		this->gameData->resource.VisualLoad("Upper Pipe", UPPER_PIPE);
		this->gameData->resource.VisualLoad("Lower Pipe", BOTTOM_PIPE);
		this->gameData->resource.VisualLoad("Land", GROUND);
		this->gameData->resource.VisualLoad("Bat 1", BAT_1);
		this->gameData->resource.VisualLoad("Bat 2", BAT_2);
		this->gameData->resource.VisualLoad("Bat 3", BAT_3);
		this->gameData->resource.VisualLoad("Bat 4", BAT_4);
		this->gameData->resource.VisualLoad("Pipe Point", PIPE_SCORE);
		this->gameData->resource.TextTypeLoad("Flappy Bat Text", FLAP_FONT);

		PIPE = new Pipe(gameData);
		land = new Ground(gameData);
		bat = new Bat(gameData);
		hud = new UserInterface(gameData);

		landscape.setTexture(this->gameData->resource.ObtainVisuals("LandScape"));

		point = 0;
		hud->RefreshScore(point);

		_gameBody = GameHandlers::eReady;
	}

	void GameBody::input_handle()
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
				if (GameHandlers::eGameOver != _gameBody)
				{
					_gameBody = GameHandlers::ePlaying;
					bat->BatJump();

					wing_sound.play();
				}
			}
		}
	}

	void GameBody::Refresh(float dt)
	{
		if (GameHandlers::eGameOver != _gameBody)
		{
			bat->Animation(dt);
			land->MoveGround(dt);
		}

		if (GameHandlers::ePlaying == _gameBody)
		{
			PIPE->pipe_movement(dt);

			if (clock.getElapsedTime().asSeconds() > PIPE_AMOUNT)
			{
				PIPE->random_pipe_spawn();

				PIPE->imaginary_pipe();
				PIPE->bot_pipe();
				PIPE->top_pipe();
				PIPE->pipe_scoring();

				clock.restart();
			}

			bat->Refresh(dt);

			std::vector<sf::Sprite> GroundImg = land->LoadSprites();

			for (int i = 0; i < GroundImg.size(); i++)
			{
				if (collision.check_collision(bat->GetSprite(), 0.7f, GroundImg.at(i), 1.0f))
				{
					_gameBody = GameHandlers::eGameOver;

					clock.restart();

					hit_sound.play();
				}
			}

			std::vector<sf::Sprite> pipeImg = PIPE->LoadSprites();

			for (int i = 0; i < pipeImg.size(); i++)
			{
				if (collision.check_collision(bat->GetSprite(), 0.625f, pipeImg.at(i), 1.0f))
				{
					_gameBody = GameHandlers::eGameOver;

					clock.restart();

					hit_sound.play();
				}
			}

			if (GameHandlers::ePlaying == _gameBody)
			{
				std::vector<sf::Sprite> &pointImg = PIPE->InitPointImg();

				for (int i = 0; i < pointImg.size(); i++)
				{
					if (collision.check_collision(bat->GetSprite(), 0.625f, pointImg.at(i), 1.0f))
					{
						point++;

						hud->RefreshScore(point);

						pointImg.erase(pointImg.begin() + i);

						point_sound.play();
					}
				}
			}
		}

		if (GameHandlers::eGameOver == _gameBody)
		{
			this->gameData->unit.add_state(StateRef(new GameEnd(gameData, point)), true);
		}
	}

	void GameBody::Render(float dt)
	{
		this->gameData->window.clear(sf::Color::Red);

		this->gameData->window.draw(this->landscape);

		PIPE->RenderPipes();
		land->RenderGround();
		bat->Render();

		hud->Render();

		this->gameData->window.display();
	}
}