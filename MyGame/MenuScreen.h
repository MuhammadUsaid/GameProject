#pragma once
#include "Screen.h"


class MenuScreen: public Screen
{
public:
    MenuScreen();
    void HandleEvents();
    void Update();
    void Render();
    ~MenuScreen();
};
