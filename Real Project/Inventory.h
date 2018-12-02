#pragma once
#include "Weapon.h"

class Inventory
{
private:
    GameObject** weapons;
    int weaponCount;
public:
    Inventory();
    void Render();
    ~Inventory();
};
