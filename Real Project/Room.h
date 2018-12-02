#pragma once
#include "Screen.h"
#include "ObjectFactory.h"
#include "ObjectList.h"
#include "Sister.h"

class Room: public Screen
{
private:
    ObjectFactory* factory;
    GameObject* objects[10];
    int roomNumber;
    Sister* sister;
public:
    Room(int);
    void HandleEvents();
    void Update();
    void Render();
    ObjectList* objectList;
    GameObject* GetCupboard();
    ~Room();
};
