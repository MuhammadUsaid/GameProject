#pragma once
#include "SDL2/SDL.h"

class Screen
{
protected:
    SDL_Texture* backGround;
public:
    Screen(){}
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void HandleEvents() = 0;
    virtual ~Screen(){}
};

