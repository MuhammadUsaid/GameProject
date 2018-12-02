#pragma once
#include "BaseCharacter.h"
#include "GameObject.h"

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
    GameObject* weapons[10];
    int weaponCount;
public:
    static Player* GetInstance();
    GameObject** GetWeapons();
    void SetWeapons(GameObject*);
    GameObject* collidingWith;
    void Update();
    void Render();
    void MoveUp();
    void MoveDown();
    void MoveRight();
    void MoveLeft();
    ~Player();
    void SetPosition(int x, int y); //WE need this when we enter a room
    void LoadWeapons(); //Initialize Weapons
    int GetWeaponCount();
    bool Top,Bottom,Left,Right;
    void DecreaseHealth(float);
    void operator+=(float);
    void operator-=(float);
    float GetHealth();
    void SetHealth(float);
};
