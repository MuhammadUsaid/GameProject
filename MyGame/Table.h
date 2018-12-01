#pragma once
#include "GameObject.h"

class Table: public GameObject
{
public:
    Table();
    Table(const char* path, int x, int y, int width, int height);
    void Render();
};
