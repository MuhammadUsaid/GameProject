#pragma once
#include "GameObject.h"



class Weapon : public GameObject
{
private:
    int range;
    int counter;
public:
    Weapon();
    Weapon(const char* path, int x, int y, int width, int height, float power, int range);
    void Update();
    SDL_Texture* GetTexture();
    SDL_Rect* GetSrc();
    virtual void Render();
    void SetRect(SDL_Rect rect);
    float power;
    ~Weapon();
};
