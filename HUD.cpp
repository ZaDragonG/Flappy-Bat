#include "HUD.h"

#include <string>

namespace Sonar
{
	HUD::HUD(game_data_ref data) : gameData(data)
	{
		pointText.setFont(this->gameData->resource.GetFont("Flappy Font")); 

		pointText.setString("0");

		pointText.setCharacterSize(128);

		pointText.setFillColor(sf::Color::White);

		pointText.setOrigin(sf::Vector2f(pointText.getGlobalBounds().width / 2, pointText.getGlobalBounds().height / 2));

		pointText.setPosition(sf::Vector2f(gameData->window.getSize().x / 2, gameData->window.getSize().y / 5));
	}

	HUD::~HUD()
	{
	}

	void HUD::Render()
	{
		gameData->window.draw(pointText);
	}

	void HUD::RefreshScore(int score)
	{
		pointText.setString(std::to_string(score));
	}
}