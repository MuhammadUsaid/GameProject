#pragma once
#include <SDL2/SDL.h>
class Health
{
private:
    int health;
    SDL_Rect healthBar; //filled rect
    SDL_Rect fullBar; //outline
    int barLength; //width
    int x, y; //position
public:
    Health();
    //~Health();
    void Update();
    void Render();
};
