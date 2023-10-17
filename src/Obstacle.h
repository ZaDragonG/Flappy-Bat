#pragma once
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "GameObject.h"

namespace FlappyBat
{
    class Obstacle : public GameObject{
        public:
            virtual void pipe_movement(float dt);
    };
}