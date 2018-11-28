#pragma once
#include <SDL2/SDL.h>
#include <iostream>

class Character
{
private:
    int x, y;
    int value = 0; //ascii value of the Character
    int width; //width of character
    int height; //height of character
    SDL_Rect spriteClips; //clip specific to the Character
    SDL_Texture* spriteSheetTexture; //font image
public:
    Character();
    Character(SDL_Texture* image, float x, float y, int ascii);
    ~Character();
    void Render(bool debug);
    void operator = (const Character& cpy); //operator overloading for assignment operatot
};

