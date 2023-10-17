#pragma once

#include "DEFINE.h"
#include "MenuBody.h"
#include "BackgroundImg.h"

#include <iostream>
#include <sstream>

namespace FlappyBat
{
	BackgroundImg::BackgroundImg(game_data_ref data) : gameData(data)
	{
	}

	void BackgroundImg::SetGameElements()
	{
		this->gameData->resource.VisualLoad("Splash State Background", SPLASH_BACKGROUND);

		landscape.setTexture(this->gameData->resource.ObtainVisuals("Splash State Background"));
	}

	void BackgroundImg::input_handle()
	{
		sf::Event event;

		while (this->gameData->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->gameData->window.close();
			}
		}
	}

	void BackgroundImg::Refresh(float dt)
	{
		if (this->_time.getElapsedTime().asSeconds() > SPLASH_TIME)
		{

			this->gameData->unit.add_state(StateRef(new MenuBody(gameData)), true);
		}
	}

	void BackgroundImg::Render(float dt)
	{
		this->gameData->window.clear(sf::Color::Red);

		this->gameData->window.draw(this->landscape);

		this->gameData->window.display();
	}
}