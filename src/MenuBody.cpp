
#include "DEFINE.h"
#include "GameBody.h"
#include "MenuBody.h"

#include <sstream>
#include <iostream>

namespace FlappyBat
{
	MenuBody::MenuBody(game_data_ref data) : gameData(data)
	{
	}

	void MenuBody::SetGameElements()
	{
		this->gameData->resource.VisualLoad("Main Menu Background", MENU_BACKGROUND);
		this->gameData->resource.VisualLoad("Game Title", TITLE);
		this->gameData->resource.VisualLoad("Play Button", PLAY);

		landscape.setTexture(this->gameData->resource.ObtainVisuals("Main Menu Background"));
		name.setTexture(this->gameData->resource.ObtainVisuals("Game Title"));
		play_switch.setTexture(this->gameData->resource.ObtainVisuals("Play Button"));

		name.setPosition((WIDTH / 2) - (name.getGlobalBounds().width / 2), name.getGlobalBounds().height / 2);
		play_switch.setPosition((WIDTH / 2) - (play_switch.getGlobalBounds().width / 2), (HEIGHT / 2) - (play_switch.getGlobalBounds().height / 2));
	}

	void MenuBody::input_handle()
	{
		sf::Event event;

		while (this->gameData->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->gameData->window.close();
			}

			if (this->gameData->input.IsSpriteClicked(this->play_switch, sf::Mouse::Left, this->gameData->window))
			{
				// button To Main Menu
				this->gameData->unit.add_state(StateRef(new GameBody(gameData)), true);
			}
		}
	}

	void MenuBody::Refresh(float)
	{
	}

	void MenuBody::Render(float)
	{
		this->gameData->window.clear(sf::Color::Red);

		this->gameData->window.draw(this->landscape);
		this->gameData->window.draw(this->name);
		this->gameData->window.draw(this->play_switch);

		this->gameData->window.display();
	}
}