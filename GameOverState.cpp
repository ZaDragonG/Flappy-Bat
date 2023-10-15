#include <sstream>
#include "DEFINITIONS.h"
#include "GameOverState.h"
#include "GameState.h"

#include <iostream>
#include <fstream>

namespace FlappyBat
{
    GameOverState::GameOverState(game_data_ref data, int score) : gameData(data), point(score)
    {
        
    }
    
    void GameOverState::Init()
    {
        std::ifstream open_file;
        open_file.open( "Resources/Highscore.txt" );
        
        if ( open_file.is_open( ) )
        {
            while ( !open_file.eof( ) )
            {
                open_file >> _highScore;
            }
        }
        
        open_file.close( );
        
        std::ofstream file_iteration( "Resources/Highscore.txt" );
        
        if ( file_iteration.is_open( ) )
        {
            if ( point > _highScore )
            {
                _highScore = point;
            }
            
            file_iteration << _highScore;
        }
        
        file_iteration.close( );
        
        this->gameData->resource.LoadTexture("Game Over Background", FATALITY_BACKGROUND);
        this->gameData->resource.LoadTexture("Game Over Title", FATALITY_TITLE);
        this->gameData->resource.LoadTexture("Game Over Body", FATALITY_BODY);
        this->gameData->resource.LoadTexture("Bronze Medal", BRON_MED);
        this->gameData->resource.LoadTexture("Silver Medal", SILV_MED);
        this->gameData->resource.LoadTexture("Gold Medal", GOLD_MED);
        this->gameData->resource.LoadTexture("Platinum Medal", PLAT_MED);
        
        landscape.setTexture(this->gameData->resource.GetTexture("Game Over Background"));
        _gameOverTitle.setTexture(this->gameData->resource.GetTexture("Game Over Title"));
        _gameOverContainer.setTexture(this->gameData->resource.GetTexture("Game Over Body"));
        _retryButton.setTexture(this->gameData->resource.GetTexture("Play Button"));
        
        _gameOverContainer.setPosition(sf::Vector2f((gameData->window.getSize().x / 2) - (_gameOverContainer.getGlobalBounds().width / 2), (gameData->window.getSize().y / 2) - (_gameOverContainer.getGlobalBounds().height / 2)));
        _gameOverTitle.setPosition(sf::Vector2f((gameData->window.getSize().x / 2) - (_gameOverTitle.getGlobalBounds().width / 2), _gameOverContainer.getPosition().y - (_gameOverTitle.getGlobalBounds().height * 1.2)));
        _retryButton.setPosition(sf::Vector2f((gameData->window.getSize().x / 2) - (_retryButton.getGlobalBounds().width / 2), _gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height + (_retryButton.getGlobalBounds().height * 0.2)));
        
        pointText.setFont(this->gameData->resource.GetFont("Flappy Font"));
        pointText.setString(std::to_string(point));
        pointText.setCharacterSize(56);
        pointText.setFillColor(sf::Color::White);
        pointText.setOrigin(sf::Vector2f(pointText.getGlobalBounds().width / 2, pointText.getGlobalBounds().height / 2));
        pointText.setPosition(sf::Vector2f(gameData->window.getSize().x / 10 * 7.25, gameData->window.getSize().y / 2.15));
        
        _highScoreText.setFont(this->gameData->resource.GetFont("Flappy Font"));
        _highScoreText.setString(std::to_string(_highScore));
        _highScoreText.setCharacterSize(56);
        _highScoreText.setFillColor(sf::Color::White);
        _highScoreText.setOrigin(sf::Vector2f(_highScoreText.getGlobalBounds().width / 2, _highScoreText.getGlobalBounds().height / 2));
        _highScoreText.setPosition(sf::Vector2f(gameData->window.getSize().x / 10 * 7.25, gameData->window.getSize().y / 1.78));
        
        if ( point >= PLATINUM_MEDAL_SCORE )
        {
            _medal.setTexture( gameData->resource.GetTexture( "Platinum Medal" ) );
        }
        else if ( point >= GOLD_MEDAL_SCORE )
        {
            _medal.setTexture( gameData->resource.GetTexture( "Gold Medal" ) );
        }
        else if ( point >= SILVER_MEDAL_SCORE )
        {
            _medal.setTexture( gameData->resource.GetTexture( "Silver Medal" ) );
        }
        else
        {
            _medal.setTexture( gameData->resource.GetTexture( "Bronze Medal" ) );
        }
        
        _medal.setPosition( 175, 465 );
    }
    
    void GameOverState::input_handle()
    {
        sf::Event event;
        
        while (this->gameData->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->gameData->window.close();
            }
            
            if (this->gameData->input.IsSpriteClicked(this->_retryButton, sf::Mouse::Left, this->gameData->window))
            {
                this->gameData->unit.add_state(StateRef(new GameState(gameData)), true);
            }
        }
    }
    
    void GameOverState::Refresh(float dt)
    {
        
    }
    
    void GameOverState::Render(float dt)
    {
        this->gameData->window.clear(sf::Color::Red);
        
        this->gameData->window.draw(this->landscape);
        
        gameData->window.draw(_gameOverTitle);
        gameData->window.draw(_gameOverContainer);
        gameData->window.draw(_retryButton);
        gameData->window.draw(pointText);
        gameData->window.draw(_highScoreText);
        
        gameData->window.draw( _medal );
        
        this->gameData->window.display();
    }
}