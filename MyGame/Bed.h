#pragma once
#include "GameObject.h"

class Bed : public GameObject
{
private:
public:
    Bed();
    Bed(const char* path, int x, int y, int width, int height);
    void Render();
};
