#pragma once
#include "Screen.h"
#include "Player.h"
#include "Health.h"

class HallScreen: public Screen
{
private:
    GameObject* walls[8];
    Player* player;
    Health* healthBar;
    void RenderWalls();
public:
    HallScreen();
    void HandleEvents();
    void Render();
    void Update();
    ~HallScreen();
};
