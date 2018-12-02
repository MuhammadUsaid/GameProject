#pragma once
#include "GameObject.h"

class ObjectFactory
{
private:
    GameObject* object;
public:
    ObjectFactory();
    GameObject* getObject(int type, const char* path, int x, int y, int width, int height, int power = 0, int range = 0);
    ~ObjectFactory();
};
