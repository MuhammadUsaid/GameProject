#pragma once
#include "Screen.h"
#include "Button.h"

class MenuScreen: public Screen
{
private:
    Button* newGameButton;
    Button* loadGameButton;
    Button* quitGameButton;
    SDL_Texture* fontSheet;
    int mouseX, mouseY;
public:
    MenuScreen();
    void HandleEvents();
    void Update();
    void Render();
    bool isRunning();
    ~MenuScreen();
};
