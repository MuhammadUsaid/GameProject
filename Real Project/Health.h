#pragma once
#include <SDL2/SDL.h>
class Health
{
private:
    float health;
    SDL_Rect healthBar; //filled rect
    SDL_Rect fullBar; //outline
    float barLength; //width
    int x, y; //position
public:
    Health();
    //~Health();
    void Update();
    void Render();
};
