#pragma once
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "GameObject.h"

namespace FlappyBat
{
    class GameObject{
        public:
            virtual void RenderPipes(float dt);
    };
}