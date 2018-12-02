#pragma once
#include "BaseCharacter.h"

class Sister: public BaseCharacter
{
public:
    Sister();
    Sister(int x, int y);
    void Render();
    ~Sister();
};
