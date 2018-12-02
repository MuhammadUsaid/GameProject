#include "PauseScreen.h"
#include "TextManager.h"

PauseScreen::PauseScreen()
{
    state = 0;
    running = true;
    Screen::pause = 3;
    fontSheet = TextureManager::LoadTexture("Images/font.png");
    resumeButton = new Button(fontSheet, " Resume ", 500, 200);
    saveButton = new Button(fontSheet, "Save Game", 500, 300);
    mainMenuButton = new Button(fontSheet, "Main Menu", 500, 400);
    quitGameButton = new Button(fontSheet, "Quit Game", 500, 500);
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
        onResumeGame = ((resumeButton->GetX() - resumeButton->GetWidth()/2) < mouseX) && ((resumeButton->GetX() + resumeButton->GetWidth()/2) > mouseX)
        && ((resumeButton->GetY() - resumeButton->GetHeight()/2) < mouseY && (resumeButton->GetY() + resumeButton->GetHeight()/2) > mouseY);
        onSaveGame = ((saveButton->GetX() - saveButton->GetWidth()/2) < mouseX) && ((saveButton->GetX() + saveButton->GetWidth()/2) > mouseX)
        && ((saveButton->GetY() - saveButton->GetHeight()/2) < mouseY && (saveButton->GetY() + saveButton->GetHeight()/2) > mouseY);
        onQuitGame = ((quitGameButton->GetX() - quitGameButton->GetWidth()/2) < mouseX) && ((quitGameButton->GetX() + quitGameButton->GetWidth()/2) > mouseX)
        && ((quitGameButton->GetY() - quitGameButton->GetHeight()/2) < mouseY && (quitGameButton->GetY() + quitGameButton->GetHeight()/2) > mouseY);
        onMainMenu = ((mainMenuButton->GetX() - mainMenuButton->GetWidth()/2) < mouseX) && ((mainMenuButton->GetX() + mainMenuButton->GetWidth()/2) > mouseX)
        && ((mainMenuButton->GetY() - mainMenuButton->GetHeight()/2) < mouseY && (mainMenuButton->GetY() + mainMenuButton->GetHeight()/2) > mouseY);
        switch(e.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_MOUSEMOTION:
            if(onResumeGame)
            {
                resumeButton->ChangeState(Hover);
            }
            else
            {
                resumeButton->ChangeState(Normal);
                if(onSaveGame)
                {
                    saveButton->ChangeState(Hover);
                }
                else
                {
                    saveButton->ChangeState(Normal);
                    if(onQuitGame)
                    {
                        quitGameButton->ChangeState(Hover);
                    }
                    else
                    {
                        quitGameButton->ChangeState(Normal);
                        if(onMainMenu)
                        {
                            mainMenuButton->ChangeState(Hover);
                        }
                        else
                        {
                            mainMenuButton->ChangeState(Normal);
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
                    resumeButton->ChangeState(Clicked);
                    Screen::pause = 2;
                }
                else if(onSaveGame)
                {
                    saveButton->ChangeState(Clicked);
                }
                else if(onQuitGame)
                {
                    quitGameButton->ChangeState(Clicked);
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
