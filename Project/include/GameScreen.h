#pragma once

#include "Screen.h"


class GameScreen : public Screen
{
    public:
        GameScreen();
        void Update();
        void Render();
        void HandleEvents();
        ~GameScreen();
};

