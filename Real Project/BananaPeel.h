#pragma once
#include "GameObject.h"

class BananaPeel: public GameObject
{
private:
public:
    BananaPeel();
    BananaPeel(const char* path, int x, int y, int width, int height);
};
