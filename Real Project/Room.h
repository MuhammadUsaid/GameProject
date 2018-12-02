#pragma once
#include "Screen.h"
#include "ObjectFactory.h"
#include "ObjectList.h"

class Room: public Screen
{
private:
    ObjectFactory* factory;
    GameObject* objects[10];
public:
    Room(int);
    void HandleEvents();
    void Update();
    void Render();
    ObjectList* objectList;
    ~Room();
};
