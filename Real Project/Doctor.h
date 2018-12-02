#pragma once
#include "BaseCharacter.h"
#include "Scalpel.h"
#include "Weapon.h"

class Doctor : public BaseCharacter
{
    //void SetClips(); //Method To store all the sprites of different motion
    bool CompareRects(SDL_Rect a, SDL_Rect b);
    int counter;
    int range;
    Weapon* weapon;
public:
    Doctor(int, int, bool, bool);
    void Update();
    void Render();
    void MoveUp();
    void MoveDown();
    void MoveRight();
    void MoveLeft();
    bool up, down;
    bool PlayerInRange();
    void Attack();
};

