#include "PauseScreen.h"
#include "TextManager.h"

PauseScreen::PauseScreen()
{
    state = 0;
    running = true;
    Screen::pause = 3;
    fontSheet = TextureManager::LoadTexture("Images/font.png");
    resumeButton = new Button(fontSheet, " Resume ", 500, 400);
    saveButton = new Button(fontSheet, "Save Game", 500, 500);
    mainMenuButton = new Button(fontSheet, "Main Menu", 500, 600);
    quitGameButton = new Button(fontSheet, "Quit Game", 500, 700);
}

void PauseScreen::HandleEvents()
{
    SDL_Event e;
    bool onResumeGame;
    bool onSaveGame;
    bool onMainMenu;
    bool onQuitGame;
    while(SDL_PollEvent(&e))
    {
        SDL_GetMouseState(&mouseX, &mouseY);
        onResumeGame = ((resumeButton->GetX() - resumeButton->getWidth()/2) < mouseX) && ((resumeButton->GetX() + resumeButton->getWidth()/2) > mouseX)
        && ((resumeButton->GetY() - resumeButton->getHeight()/2) < mouseY && (resumeButton->GetY() + resumeButton->getHeight()/2) > mouseY);
        onSaveGame = ((saveButton->GetX() - saveButton->getWidth()/2) < mouseX) && ((saveButton->GetX() + saveButton->getWidth()/2) > mouseX)
        && ((saveButton->GetY() - saveButton->getHeight()/2) < mouseY && (saveButton->GetY() + saveButton->getHeight()/2) > mouseY);
        onQuitGame = ((quitGameButton->GetX() - quitGameButton->getWidth()/2) < mouseX) && ((quitGameButton->GetX() + quitGameButton->getWidth()/2) > mouseX)
        && ((quitGameButton->GetY() - quitGameButton->getHeight()/2) < mouseY && (quitGameButton->GetY() + quitGameButton->getHeight()/2) > mouseY);
        onMainMenu = ((mainMenuButton->GetX() - mainMenuButton->getWidth()/2) < mouseX) && ((mainMenuButton->GetX() + mainMenuButton->getWidth()/2) > mouseX)
        && ((mainMenuButton->GetY() - mainMenuButton->getHeight()/2) < mouseY && (mainMenuButton->GetY() + mainMenuButton->getHeight()/2) > mouseY);
        switch(e.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_MOUSEMOTION:
            if(onResumeGame)
            {
                resumeButton->changeState(Hover);
            }
            else
            {
                resumeButton->changeState(Normal);
                if(onSaveGame)
                {
                    saveButton->changeState(Hover);
                }
                else
                {
                    saveButton->changeState(Normal);
                    if(onQuitGame)
                    {
                        quitGameButton->changeState(Hover);
                    }
                    else
                    {
                        quitGameButton->changeState(Normal);
                        if(onMainMenu)
                        {
                            mainMenuButton->changeState(Hover);
                        }
                        else
                        {
                            mainMenuButton->changeState(Normal);
                        }
                    }
                }

            }

            break;
        case SDL_MOUSEBUTTONDOWN:
            if(e.button.button == SDL_BUTTON_LEFT)
            {
                if(onResumeGame)
                {
                    resumeButton->changeState(Clicked);
                    Screen::pause = 2;
                }
                else if(onSaveGame)
                {
                    saveButton->changeState(Clicked);
                }
                else if(onQuitGame)
                {
                    quitGameButton->changeState(Clicked);
                    running = false;
                }
                else if(onMainMenu)
                {
                    state = 2;
                    Screen::pause = 2;
                }
            }
            break;
        }
    }

}
void PauseScreen::Update()
{

}
void PauseScreen::Render()
{
    resumeButton->Render();
    saveButton->Render();
    mainMenuButton->Render();
    quitGameButton->Render();
}
PauseScreen::~PauseScreen()
{
    SDL_DestroyTexture(fontSheet);
    delete resumeButton;
    delete saveButton;
    delete mainMenuButton;
    delete quitGameButton;
}
