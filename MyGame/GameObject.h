#pragma once
#include <SDL2/SDL.h>
class GameObject
{
protected:
    int x;
    int y;
    int width;
    int height;
    SDL_Texture* texture;
    SDL_Rect dstRect;
    SDL_Rect srcRect;
public:
    GameObject();
    GameObject(const char* path, int x, int y, int width, int height);
    SDL_Rect GetRect();
    virtual void Update();
    virtual void Render();
    ~GameObject();
};
