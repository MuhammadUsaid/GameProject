#pragma once
#include "BaseCharacter.h"
#include "Weapon.h"

class Player: public BaseCharacter
{
private:
    static Player* instance;
    Player();
    void SetClips(); //Method To store all the sprites of different motion
    bool CompareRects(SDL_Rect a, SDL_Rect b);
    SDL_Rect moveUp[4];
    SDL_Rect moveDown[4];
    SDL_Rect moveRight[4];
    SDL_Rect moveLeft[4];
    Weapon* weapons;
public:
    static Player* GetInstance();
    Weapon* GetWeapons();
    void Update();
    void Render();
    void MoveUp();
    void MoveDown();
    void MoveRight();
    void MoveLeft();
    ~Player();
};
