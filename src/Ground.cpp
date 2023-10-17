#include "DEFINE.h"
#include "Ground.h"

namespace FlappyBat
{
	Land::Land(game_data_ref data) : gameData(data)
	{
		sf::Sprite sprite(this->gameData->resource.ObtainVisuals("Land"));
		sf::Sprite sprite_2(this->gameData->resource.ObtainVisuals("Land"));

		sprite.setPosition(0, this->gameData->window.getSize().y - sprite.getLocalBounds().height);
		sprite_2.setPosition(sprite.getLocalBounds().width, this->gameData->window.getSize().y - sprite_2.getLocalBounds().height);

		ground_sprite.push_back(sprite);
		ground_sprite.push_back(sprite_2);
	}

	void Land::MoveLand(float dt)
	{
		for (unsigned short int i = 0; i < ground_sprite.size(); i++)
		{
			sf::Vector2f position = ground_sprite.at(i).getPosition();
			float move = PIPE_SPEED * dt;

			ground_sprite.at(i).move(-move, 0.0f);

			if (ground_sprite.at(i).getPosition().x < 0 - ground_sprite.at(i).getLocalBounds().width)
			{
				sf::Vector2f position(gameData->window.getSize().x, ground_sprite.at(i).getPosition().y);

				ground_sprite.at(i).setPosition(position);
			}
		}
	}

	void Land::RenderLand()
	{
		for (unsigned short int i = 0; i < ground_sprite.size(); i++)
		{
			this->gameData->window.draw(ground_sprite.at(i));
		}
	}

	const std::vector<sf::Sprite> &Land::GetSprites() const
	{
		return ground_sprite;
	}
}