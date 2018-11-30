#pragma once
#include "Weapon.h"

class Apple : public Weapon
{
private:
public:
    Apple();
    Apple(const char* path, int x, int y, int width, int height, int power, int range);
    ~Apple();
};
