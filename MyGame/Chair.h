#pragma once
#include "GameObject.h"

class Chair : public GameObject
{
private:
public:
    Chair();
    Chair(const char* path, int x, int y, int width, int height);
    void Render();
};
