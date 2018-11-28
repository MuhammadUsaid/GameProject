#pragma once
#include "Screen.h"
#include "Button.h"

class PauseScreen: public Screen
{
private:
    SDL_Texture* fontSheet;
    Button* mainMenuButton;
    Button* resumeButton;
    Button* saveButton;
    Button* quitGameButton;
    int mouseX, mouseY;
public:
    PauseScreen();
    void Update();
    void HandleEvents();
    void Render();
    ~PauseScreen();
};
