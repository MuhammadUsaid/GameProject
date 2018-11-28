#pragma once
#include "Screen.h"
#include "Player.h"
#include "Health.h"

class HallScreen: public Screen
{
private:
    Player* player;
    Health* healthBar;
public:
    HallScreen();
    void HandleEvents();
    void Render();
    void Update();
    ~HallScreen();
};
