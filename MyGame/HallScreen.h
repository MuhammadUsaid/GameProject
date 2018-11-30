#pragma once
#include "Screen.h"
#include "Player.h"
#include "Health.h"
#include "ObjectList.h"
#include "Bed.h"
#include "Cupboard.h"
#include "Chair.h"
#include <iostream>

class ObjectFactory
{
private:
    GameObject* object;
public:
    ObjectFactory()
    {
        object = nullptr;
    }
    GameObject* getObject(int type, int x, int y, int width, int height)
    {
        switch(type)
        {
        case 0:
            object = new Bed("Images/sprite.png", x, y, width, height);
            break;
        case 1:
            object = new Chair("Images/sprite.png", x, y, width, height);
            break;
        case 2:
            object = new Cupboard("Images/sprite.png", x, y, width, height);
            std::cout << "THERE THERE";
            break;
        case 3:
            object = new GameObject("Images/wall.png", x, y, width, height);
            break;
        }
        return object;
    }
    ~ObjectFactory(){}
};

class HallScreen: public Screen
{
private:
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
