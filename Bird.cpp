#include "Bird.h"

namespace FlappyBat
{
	Bat::Bat(game_data_ref data) : gameData(data)
	{
		animation_change = 0;

		anime_frame.push_back(this->gameData->resource.GetTexture("Bird Frame 1"));
		anime_frame.push_back(this->gameData->resource.GetTexture("Bird Frame 2"));
		anime_frame.push_back(this->gameData->resource.GetTexture("Bird Frame 3"));
		anime_frame.push_back(this->gameData->resource.GetTexture("Bird Frame 4"));

		bat_sprite.setTexture(anime_frame.at(animation_change));

		bat_sprite.setPosition((gameData->window.getSize().x / 4) - (bat_sprite.getGlobalBounds().width / 2), (gameData->window.getSize().y / 2) - (bat_sprite.getGlobalBounds().height / 2));
	
		bat_state = BAT_STILL;

		sf::Vector2f origin = sf::Vector2f(bat_sprite.getGlobalBounds().width / 2, bat_sprite.getGlobalBounds().height / 2);

		bat_sprite.setOrigin(origin);

		bat_rotate = 0;
	}

	Bat::~Bat()
	{
	}

	void Bat::Render()
	{
		gameData->window.draw(bat_sprite);
	}

	void Bat::Animation(float dt)
	{
		if (_time.getElapsedTime().asSeconds() > BAT_DURATION / anime_frame.size())
		{
			if (animation_change < anime_frame.size() - 1)
			{
				animation_change++;
			}
			else
			{
				animation_change = 0;
			}

			bat_sprite.setTexture(anime_frame.at(animation_change));

			_time.restart();
		}
	}

	void Bat::Refresh(float dt)
	{
		if (BAT_FALLING == bat_state)
		{
			bat_sprite.move(0, GRAV * dt);

			bat_rotate += ROTATE_VELOCITY * dt;

			if (bat_rotate > 25.0f)
			{
				bat_rotate = 25.0f;
			}

			bat_sprite.setRotation(bat_rotate);
		}
		else if (BAT_FLYING == bat_state)
		{
			bat_sprite.move(0, -FLIGHT_VELOCITY * dt);

			bat_rotate -= ROTATE_VELOCITY * dt;

			if (bat_rotate < -25.0f)
			{
				bat_rotate = -25.0f;
			}

			bat_sprite.setRotation(bat_rotate);
		}

		if (movement_clock.getElapsedTime().asSeconds() > FLIGHT_TIME)
		{
			movement_clock.restart();
			bat_state = BAT_FALLING;
		}
	}

	void Bat::BatJump()
	{
		movement_clock.restart();
		bat_state = BAT_FLYING;
	}

	const sf::Sprite &Bat::GetSprite() const
	{
		return bat_sprite;
	}
}