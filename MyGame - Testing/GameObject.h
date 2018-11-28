#pragma once
#include "SDL2/SDL.h"
//#include "Game.h"

class GameObject
{
protected:
    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect dstRect;
    int x, y;
    int width, height;
public:
    GameObject(){}
    GameObject(const char* path, int x, int y, int width, int height){}
    int GetX(){ return x; }
    int GetY(){ return y;}
    void Update(){}
    void Render(){}
};
