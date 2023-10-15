#pragma once

#define WIDTH 768
#define HEIGHT 1024

#define SPLASH_TIME 0.0

#define SPLASH_BACKGROUND "Resources/res/Splash Background.png"
#define MENU_BACKGROUND "Resources/res/sky.png"
#define BACKGROUND "Resources/res/sky.png"
#define FATALITY_BACKGROUND "Resources/res/sky.png"

#define TITLE "Resources/res/title.png"
#define PLAY "Resources/res/PlayButton.png"

#define UPPER_PIPE "Resources/res/PipeUp.png"
#define BOTTOM_PIPE "Resources/res/PipeDown.png"

#define GROUND "Resources/res/land.png"

#define BAT_1 "Resources/res/bird-01.png"
#define BAT_2 "Resources/res/bird-02.png"
#define BAT_3 "Resources/res/bird-03.png"
#define BAT_4 "Resources/res/bird-04.png"

#define PIPE_SCORE "Resources/res/InvisibleScoringPipe.png"

#define FLAP_FONT "Resources/fonts/FlappyFont.ttf"

#define FATALITY_TITLE "Resources/res/Game-Over-Title.png"
#define FATALITY_BODY "Resources/res/Game-Over-Body.png"

#define BRON_MED "Resources/res/Bronze-Medal.png"
#define SILV_MED "Resources/res/Silver-Medal.png"
#define GOLD_MED "Resources/res/Gold-Medal.png"
#define PLAT_MED "Resources/res/Platinum-Medal.png"

#define HIT_AUDIO "Resources/audio/Hit.wav"
#define POINT_AUDIO "Resources/audio/Point.wav"
#define WING_AUDIO "Resources/audio/Wing.wav"

#define PIPE_SPEED 200.0f
#define PIPE_AMOUNT 1.5f

#define BAT_DURATION 0.4f

#define BAT_STILL 1
#define BAT_FALLING 2
#define BAT_FLYING 3

#define GRAV 350.0f
#define FLIGHT_VELOCITY 350.0f

#define FLIGHT_TIME 0.25f

#define ROTATE_VELOCITY 100.0f

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};

#define FLASH_SPEED 1500.0f

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f

#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 5
#define GOLD_MEDAL_SCORE 25
#define PLATINUM_MEDAL_SCORE 100