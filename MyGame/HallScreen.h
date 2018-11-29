#pragma once
#include "Screen.h"
#include "Player.h"
#include "Health.h"
#include "ObjectList.h"
#include "Bed.h"
#include "Cupboard.h"
#include "Chair.h"

class HallScreen: public Screen
{
private:
    ObjectList* objList;
    GameObject* walls[8];
    Player* player;
    Health* healthBar;
    Bed* beds[4];
    Cupboard* cupboards[4];
    Chair* chairs[4];
    void InitializeChairs();
    void InitializeCupboards();
    void InitializeWalls();
    void InitializeBeds();
    void AddObjects();
    bool PointInRect(int x , int y, SDL_Rect);
    bool CheckCollision(SDL_Rect, SDL_Rect);
public:
    HallScreen();
    void HandleEvents();
    void Render();
    void Update();
    ~HallScreen();
};
