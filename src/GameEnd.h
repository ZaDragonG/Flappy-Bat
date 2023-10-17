#pragma once

#include "Virtual.h"
#include "Game.h"

#include <SFML/Graphics.hpp>

namespace FlappyBat
{
    class GameOverState : public State
    {
    public:
        GameOverState(game_data_ref data, int score);

        void Init();

        void input_handle();
        void Refresh(float dt);
        void Render(float dt);

    private:
        game_data_ref gameData;

        sf::Sprite landscape;

        sf::Sprite _gameOverTitle;
        sf::Sprite _gameOverContainer;
        sf::Sprite _retryButton;
        sf::Sprite _medal;

        sf::Text pointText;
        sf::Text _highScoreText;

        int point;
        int _highScore;
    };
}
