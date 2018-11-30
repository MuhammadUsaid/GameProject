#pragma once
#include "GameObject.h"

class Weapon : public GameObject
{
private:
    int power;
    int range;
public:
    Weapon();
    Weapon(const char* path, int x, int y, int width, int height, int power, int range);
    void Update();
    virtual void Render();
//    void SetDstRect(int x, int y, int w, int h);
    ~Weapon();
};
