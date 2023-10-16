#include "Flash.h"

namespace Sonar
{
	Flash::Flash(game_data_ref data) : gameData(data)
	{
		structure = sf::RectangleShape(sf::Vector2f(gameData->window.getSize().x, gameData->window.getSize().y));
		structure.setFillColor(sf::Color(255, 255, 255, 0));

		flash_on = true;
	}

	Flash::~Flash()
	{
	}

	void Flash::Display(float dt)
	{
		if (flash_on)
		{
			int number_1 = (int)structure.getFillColor().a + (FLASH_SPEED * dt);

			if (number_1 >= 255.0f)
			{
				number_1 = 255.0f;
				flash_on = false;
			}

			structure.setFillColor(sf::Color(255, 255, 255, number_1));
		}
		else
		{
			int number_1 = (int)structure.getFillColor().a - (FLASH_SPEED * dt);

			if (number_1 <= 0.0f)
			{
				number_1 = 0.0f;
			}

			structure.setFillColor(sf::Color(255, 255, 255, number_1));
		}
	}

	void Flash::Render()
	{
		gameData->window.draw(structure);
	}
}
