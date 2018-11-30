#pragma once
#include "Weapon.h"

class Inventory
{
private:
    Weapon* weapons;
public:
    Inventory();
    void Render();
    ~Inventory();
};
