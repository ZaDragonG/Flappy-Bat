#pragma once

#include <SFML/Graphics.h>
#include "Game.h"
#include "DEFINITIONS.h"

namespace Sonar
{
	class Flash
	{
	public:
		Flash(GameDataRef data);
		~Flash();

		void Show(float dt);
		void Draw();

	private:
		GameDataRef _data;

		sf::RectangleShape _shape;

		bool _flashOn;

	};
}
