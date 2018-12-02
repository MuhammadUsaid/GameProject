#include "Scalpel.h"

Scalpel::Scalpel(){}

Scalpel::Scalpel(const char* path, int x, int y, int width, int height, float power, int range): Weapon(path, x, y, width, height, power, range)
{
    srcRect = {850, 70, 70, 165};
    this->power = power;
    type = SCALPEL;
}

