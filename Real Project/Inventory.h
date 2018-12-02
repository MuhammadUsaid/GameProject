#pragma once
#include "Weapon.h"
#include "Key.h"

class Inventory
{
private:
    GameObject** weapons;
    Key* key;
    int weaponCount;
public:
    Inventory();
    void Render();
    ~Inventory();
};
