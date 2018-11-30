#pragma once
#include "Weapon.h"

class Scissor: public Weapon
{
private:
public:
    Scissor();
    Scissor(const char* path, int x, int y, int width, int height, int power, int range);

};
