#pragma once
#include "Screen.h"
#include "Button.h"

class QuitScreen: public Screen
{
private:
    Button* newGameButton;
    Button* loadGameButton;
    Button* mainMenuButton;
    Button* quitGameButton;
    SDL_Texture* fontSheet;
    int mouseX, mouseY;
public:
    QuitScreen();
    void HandleEvents();
    void Render();
    void Update();
    ~QuitScreen();
};
