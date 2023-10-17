#pragma once

#include "ButtonInputs.h"

namespace FlappyBat
{
	bool ButtonInputs::IsSpriteClicked(sf::Sprite thing, sf::Mouse::Button button, sf::RenderWindow &window)
	{
		if (sf::Mouse::isButtonPressed(button))
		{
			sf::IntRect playButtonRect(thing.getPosition().x, thing.getPosition().y, thing.getGlobalBounds().width, thing.getGlobalBounds().height);

			if (playButtonRect.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		}

		return false;
	}

	sf::Vector2i ButtonInputs::GetMousePosition(sf::RenderWindow &window)
	{
		return sf::Mouse::getPosition(window);
	}
}