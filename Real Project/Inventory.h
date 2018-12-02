#pragma once
#include "Weapon.h"

class Inventory
{
private:
    GameObject** weapons;
public:
    Inventory();
    void Render();
    ~Inventory();
};
