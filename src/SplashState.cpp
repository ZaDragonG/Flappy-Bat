#pragma once

#include <sstream>
#include "SplashState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"

#include <iostream>

namespace FlappyBat
{
	SplashState::SplashState(game_data_ref data) : gameData(data)
	{

	}

	void SplashState::Init()
	{
		this->gameData->resource.VisualLoad("Splash State Background", SPLASH_BACKGROUND);

		landscape.setTexture(this->gameData->resource.GetTexture("Splash State Background"));
	}

	void SplashState::input_handle()
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

	void SplashState::Refresh(float dt)
	{
		if (this->_time.getElapsedTime().asSeconds() > SPLASH_TIME)
		{

			this->gameData->unit.add_state(StateRef(new MainMenuState(gameData)), true);
		}
	}

	void SplashState::Render(float dt)
	{
		this->gameData->window.clear(sf::Color::Red);

		this->gameData->window.draw( this->landscape );

		this->gameData->window.display();
	}
}