#pragma once
#include "BaseCharacter.h"
#include "Weapon.h"
#include "Injection.h"
//#include "Player.h"

class Nurse : public BaseCharacter
{
    //void SetClips(); //Method To store all the sprites of different motion
    bool CompareRects(SDL_Rect a, SDL_Rect b);
    SDL_Rect moveUp[4];
    SDL_Rect moveDown[4];
    SDL_Rect moveRight[4];
    SDL_Rect moveLeft[4];
    int counter;
    int range;
    Weapon* weapon;

public:
    Nurse(int, int, bool, bool);
    void Update();
    void Render();
    void MoveUp();
    void MoveDown();
    void MoveRight();
    void MoveLeft();
    bool left, right;
    bool PlayerInRange();
    void Attack();
};



