#pragma once
#include "GameObject.h"

class Cupboard : public GameObject
{
private:
    bool containsKey;
public:
    Cupboard();
    bool GetKeyState();
    Cupboard(const char* path, int x, int y, int width, int height);
    void Render();
    void SetKeyState(bool);
};
