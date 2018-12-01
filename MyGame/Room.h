#pragma once
#include "Screen.h"
#include "ObjectFactory.h"
#include "ObjectList.h"

class Room: public Screen
{
private:
    ObjectFactory* factory;
    GameObject* objects[10];
    ObjectList* objectList;
public:
    Room();
    void HandleEvents();
    void Update();
    void Render();
    ~Room();
};
