#pragma once
#include "GameObject.h"

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
            object = new Bed("Images/sprites.png", x, y, width, height);
            break;
        case 1:
            object = new Chair("Images/sprites.png", x, y, width, height);
            break;
        case 2:
            object = new Cupboard("Images/sprites.png", x, y, width, height);
            break;
        case 3:
            object = new GameObject("Images/wall.png", x, y, width, height);
            break;
        }
        return object;
    }
    ~ObjectFactory(){}
};

#endif // OBJECTFACTORY_H
