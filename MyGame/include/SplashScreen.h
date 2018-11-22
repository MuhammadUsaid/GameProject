#pragma once
#include "Screen.h"

class SplashScreen: public Screen
{
public:
    SplashScreen();
    void Update();
    void Render();
    void HandleEvents();
    ~SplashScreen();
};
