#pragma once
#include "SDL2/SDL.h"

class Screen
{
protected:
    SDL_Texture* backGround;
    bool running;
    int state;
public:
    Screen(){}
    static int pause;
    int GetState(){ return state; }
    bool IsRunning(){ return running; }
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void HandleEvents() = 0;
    virtual ~Screen(){}
};

