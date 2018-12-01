#pragma once
#include "Screen.h"
#include "Player.h"
#include "Health.h"
#include "ObjectList.h"
#include "Bed.h"
#include "Cupboard.h"
#include "Chair.h"
#include "Table.h"
#include "ObjectFactory.h"
#include <iostream>

class HallScreen: public Screen
{
private:
    int roomNumber;
    Screen* roomScreen[4];
    void InitializeRooms();
protected:
    ObjectList* objList;
    ObjectFactory* o;
    GameObject* object;
    GameObject* walls[8];
    Player* player;
    Health* healthBar;
    Bed* beds[4];
    GameObject* cupBoard;
    GameObject* cupboards[4];
    Chair* chairs[4];
    void InitializeChairs();
    void InitializeCupboards();
    void InitializeWalls();
    void InitializeBeds();
    void AddObjects();
public:
    HallScreen();
    void HandleEvents();
    void Render();
    void Update();
    ~HallScreen();
};
