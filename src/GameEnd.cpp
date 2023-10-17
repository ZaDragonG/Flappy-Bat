#include "DEFINE.h"
#include "GameEnd.h"
#include "GameBody.h"

#include <fstream>
#include <iostream>
#include <sstream>

namespace FlappyBat
{
    GameEnd::GameEnd(game_data_ref data, int score) : gameData(data), point(score)
    {
    }

    void GameEnd::SetGameElements()
    {
        std::ifstream open_file;
        open_file.open("assets/Highscore.txt");

        if (open_file.is_open())
        {
            while (!open_file.eof())
            {
                open_file >> _highScore;
            }
        }

        open_file.close();

        std::ofstream file_iteration("assets/Highscore.txt");

        if (file_iteration.is_open())
        {
            if (point > _highScore)
            {
                _highScore = point;
            }

            file_iteration << _highScore;
        }

        file_iteration.close();

        this->gameData->resource.VisualLoad("Game Over Background", FATALITY_BACKGROUND);
        this->gameData->resource.VisualLoad("Game Over Title", FATALITY_TITLE);
        this->gameData->resource.VisualLoad("Game Over Body", FATALITY_BODY);
        this->gameData->resource.VisualLoad("Bronze Medal", BRON_MED);
        this->gameData->resource.VisualLoad("Silver Medal", SILV_MED);
        this->gameData->resource.VisualLoad("Gold Medal", GOLD_MED);
        this->gameData->resource.VisualLoad("Platinum Medal", PLAT_MED);

        landscape.setTexture(this->gameData->resource.ObtainVisuals("Game Over Background"));
        _endGameText.setTexture(this->gameData->resource.ObtainVisuals("Game Over Title"));
        _endGameHold.setTexture(this->gameData->resource.ObtainVisuals("Game Over Body"));
        _playAgainInput.setTexture(this->gameData->resource.ObtainVisuals("Play Button"));

        _endGameHold.setPosition(sf::Vector2f((gameData->window.getSize().x / 2) - (_endGameHold.getGlobalBounds().width / 2), (gameData->window.getSize().y / 2) - (_endGameHold.getGlobalBounds().height / 2)));
        _endGameText.setPosition(sf::Vector2f((gameData->window.getSize().x / 2) - (_endGameText.getGlobalBounds().width / 2), _endGameHold.getPosition().y - (_endGameText.getGlobalBounds().height * 1.2)));
        _playAgainInput.setPosition(sf::Vector2f((gameData->window.getSize().x / 2) - (_playAgainInput.getGlobalBounds().width / 2), _endGameHold.getPosition().y + _endGameHold.getGlobalBounds().height + (_playAgainInput.getGlobalBounds().height * 0.2)));

        pointText.setFont(this->gameData->resource.ObtainText("Flappy Bat Text"));
        pointText.setString(std::to_string(point));
        pointText.setCharacterSize(56);
        pointText.setFillColor(sf::Color::White);
        pointText.setOrigin(sf::Vector2f(pointText.getGlobalBounds().width / 2, pointText.getGlobalBounds().height / 2));
        pointText.setPosition(sf::Vector2f(gameData->window.getSize().x / 10 * 7.25, gameData->window.getSize().y / 2.15));

        _highScoreText.setFont(this->gameData->resource.ObtainText("Flappy Bat Text"));
        _highScoreText.setString(std::to_string(_highScore));
        _highScoreText.setCharacterSize(56);
        _highScoreText.setFillColor(sf::Color::White);
        _highScoreText.setOrigin(sf::Vector2f(_highScoreText.getGlobalBounds().width / 2, _highScoreText.getGlobalBounds().height / 2));
        _highScoreText.setPosition(sf::Vector2f(gameData->window.getSize().x / 10 * 7.25, gameData->window.getSize().y / 1.78));

        if (point >= PLATINUM_MEDAL_SCORE)
        {
            _medal.setTexture(gameData->resource.ObtainVisuals("Platinum Medal"));
        }
        else if (point >= GOLD_MEDAL_SCORE)
        {
            _medal.setTexture(gameData->resource.ObtainVisuals("Gold Medal"));
        }
        else if (point >= SILVER_MEDAL_SCORE)
        {
            _medal.setTexture(gameData->resource.ObtainVisuals("Silver Medal"));
        }
        else
        {
            _medal.setTexture(gameData->resource.ObtainVisuals("Bronze Medal"));
        }

        _medal.setPosition(175, 465);
    }

    void GameEnd::input_handle()
    {
        sf::Event event;

        while (this->gameData->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->gameData->window.close();
            }

            if (this->gameData->input.IsSpriteClicked(this->_playAgainInput, sf::Mouse::Left, this->gameData->window))
            {
                this->gameData->unit.add_state(StateRef(new GameBody(gameData)), true);
            }
        }
    }

    void GameEnd::Refresh(float dt)
    {
    }

    void GameEnd::Render(float dt)
    {
        this->gameData->window.clear(sf::Color::Red);

        this->gameData->window.draw(this->landscape);

        gameData->window.draw(_endGameText);
        gameData->window.draw(_endGameHold);
        gameData->window.draw(_playAgainInput);
        gameData->window.draw(pointText);
        gameData->window.draw(_highScoreText);

        gameData->window.draw(_medal);

        this->gameData->window.display();
    }
}