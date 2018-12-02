#pragma once
#include "GameObject.h"

class Door : public GameObject
{
private:
public:
    Door();
    Door(const char* path, int x, int y, int width, int height);
    void Render();
};

