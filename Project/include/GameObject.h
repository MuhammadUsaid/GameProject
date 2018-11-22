#pragma once
#include "Game.h"

class GameObject
{
protected:
    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect dstRect;
    int x, y;
    int width, height;
public:
    GameObject();
    GameObject(const char* path, int x, int y, int width, int height);
    void Update();
    void Render();
};
