#include "Collision.h"
#include <iostream>
namespace Sonar
{
	Collision::Collision()
	{
	}

	Collision::~Collision()
	{
	}

	bool Collision::check_collision(sf::Sprite sprite_1, sf::Sprite sprite_2)
	{
		sf::Rect<float> rect1 = sprite_1.getGlobalBounds();
		sf::Rect<float> rect2 = sprite_2.getGlobalBounds();

		if (rect1.intersects(rect2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Collision::check_collision(sf::Sprite sprite_1, float scale_1, sf::Sprite sprite_2, float scale_2)
	{
		sprite_1.setScale(scale_1, scale_1);
		sprite_2.setScale(scale_2, scale_2);

		sf::Rect<float> rect1 = sprite_1.getGlobalBounds();
		sf::Rect<float> rect2 = sprite_2.getGlobalBounds();

		if (rect1.intersects(rect2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}