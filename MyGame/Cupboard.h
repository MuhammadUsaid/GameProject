#pragma once
#include "GameObject.h"

class Cupboard : public GameObject
{
private:
public:
    Cupboard();
    Cupboard(const char* path, int x, int y, int width, int height);
    void Render();
};
