#pragma once
#include "Weapon.h"

class Injection: public Weapon
{
private:
public:
    Injection();
    Injection(const char* path, int x, int y, int width, int height, int power, int range);
    //Render();
    //~Injection();
};
