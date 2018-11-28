#pragma once
#include "Screen.h"
#include "Player.h"

class HallScreen: public Screen
{
private:
    Player* player;
public:
    HallScreen();
    void HandleEvents();
    void Render();
    void Update();
    ~HallScreen();
};
