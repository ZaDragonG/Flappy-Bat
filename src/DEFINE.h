#pragma once

#define WIDTH 768
#define HEIGHT 1024

#define SPLASH_TIME 0.0

#define SPLASH_BACKGROUND "assets/img/Splash Background.png"
#define MENU_BACKGROUND "assets/img/sky.png"
#define BACKGROUND "assets/img/sky.png"
#define FATALITY_BACKGROUND "assets/img/sky.png"

#define TITLE "assets/img/title.png"
#define PLAY "assets/img/PlayButton.png"

#define UPPER_PIPE "assets/img/PipeUp.png"
#define BOTTOM_PIPE "assets/img/PipeDown.png"

#define GROUND "assets/img/land.png"

#define BAT_1 "assets/img/bird-01.png"
#define BAT_2 "assets/img/bird-02.png"
#define BAT_3 "assets/img/bird-03.png"
#define BAT_4 "assets/img/bird-04.png"

#define PIPE_SCORE "assets/img/InvisibleScoringPipe.png"

#define FLAP_FONT "assets/fonts/comicz.ttf"

#define FATALITY_TITLE "assets/img/Game-Over-Title.png"
#define FATALITY_BODY "assets/img/Game-Over-Body.png"

#define BRON_MED "assets/img/Bronze-Medal.png"
#define SILV_MED "assets/img/Silver-Medal.png"
#define GOLD_MED "assets/img/Gold-Medal.png"
#define PLAT_MED "assets/img/Platinum-Medal.png"

#define HIT_AUDIO "assets/audio/Hit.wav"
#define POINT_AUDIO "assets/audio/Point.wav"
#define WING_AUDIO "assets/audio/Wing.wav"

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

enum GameHandlers
{
	eReady,
	ePlaying,
	eGameOver,
};

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f

#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 5
#define GOLD_MEDAL_SCORE 25
#define PLATINUM_MEDAL_SCORE 100
