#pragma once

#include "Virtual.h"
#include "Game.h"

#include <SFML/Graphics.hpp>

namespace FlappyBat
{
    class GameEnd : public Virtual
    {
    public:
        GameEnd(game_data_ref data, int score);

        void SetGameElements();

        void input_handle();
        void Refresh(float dt);
        void Render(float dt);

    private:
        game_data_ref gameData;

        sf::Sprite landscape;

        sf::Sprite _endGameText;
        sf::Sprite _endGameHold;
        sf::Sprite _playAgainInput;
        sf::Sprite _medal;

        sf::Text pointText;
        sf::Text _highScoreText;

        int point;
        int _highScore;
    };
}
