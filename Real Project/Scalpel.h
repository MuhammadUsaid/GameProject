#pragma once
#include "Weapon.h"

class Scalpel: public Weapon
{
private:
public:
    Scalpel();
    Scalpel(const char* path, int x, int y, int width, int height, float power, int range);

};
