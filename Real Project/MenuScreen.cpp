#include "MenuScreen.h"
#include "TextManager.h"
#include "Button.h"

MenuScreen::MenuScreen()
{
    state = 0;
    running = true;
//    Screen::pause = 0;
    backGround = TextureManager::LoadTexture("Images/menu.png");
    fontSheet = TextureManager::LoadTexture("Images/font.png");
    newGameButton = new Button(fontSheet, " New Game ", 500, 400);
    loadGameButton = new Button(fontSheet, "Load Game", 500, 500);
    quitGameButton = new Button(fontSheet, "Quit Game", 500, 600);
}

void MenuScreen::HandleEvents()
{
    SDL_Event e;
    bool onNewGame;
    bool onLoadGame;
    bool onQuitGame;
    while(SDL_PollEvent(&e))
    {
        SDL_GetMouseState(&mouseX, &mouseY);
        onNewGame = ((newGameButton->GetX() - newGameButton->GetWidth()/2) < mouseX) && ((newGameButton->GetX() + newGameButton->GetWidth()/2) > mouseX)
        && ((newGameButton->GetY() - newGameButton->GetHeight()/2) < mouseY && (newGameButton->GetY() + newGameButton->GetHeight()/2) > mouseY);
        onLoadGame = ((loadGameButton->GetX() - loadGameButton->GetWidth()/2) < mouseX) && ((loadGameButton->GetX() + loadGameButton->GetWidth()/2) > mouseX)
        && ((loadGameButton->GetY() - loadGameButton->GetHeight()/2) < mouseY && (loadGameButton->GetY() + loadGameButton->GetHeight()/2) > mouseY);
        onQuitGame = ((quitGameButton->GetX() - quitGameButton->GetWidth()/2) < mouseX) && ((quitGameButton->GetX() + quitGameButton->GetWidth()/2) > mouseX)
        && ((quitGameButton->GetY() - quitGameButton->GetHeight()/2) < mouseY && (quitGameButton->GetY() + quitGameButton->GetHeight()/2) > mouseY);
        switch(e.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_MOUSEMOTION:
            if(onNewGame)
            {
                newGameButton->ChangeState(Hover);
            }
            else
            {
                newGameButton->ChangeState(Normal);
                if(onLoadGame)
                {
                    loadGameButton->ChangeState(Hover);
                }
                else
                {
                    loadGameButton->ChangeState(Normal);
                    if(onQuitGame)
                    {
                        quitGameButton->ChangeState(Hover);
                    }
                    else
                    {
                        quitGameButton->ChangeState(Normal);
                    }
                }

            }

            break;
        case SDL_MOUSEBUTTONDOWN:
            if(e.button.button == SDL_BUTTON_LEFT)
            {
                if(onNewGame)
                {
                    newGameButton->ChangeState(Clicked);
                    state = 1;
                }
                else if(onLoadGame)
                {
                    loadGameButton->ChangeState(Clicked);
                }
                else if(onQuitGame)
                {
                    quitGameButton->ChangeState(Clicked);
                    running = false;
                }
            }
            break;
        }
    }
}
void MenuScreen::Update()
{

}
void MenuScreen::Render()
{
    SDL_RenderCopy(Game::renderer, backGround, nullptr, nullptr);
    newGameButton->Render();
    loadGameButton->Render();
    quitGameButton->Render();
}
MenuScreen::~MenuScreen()
{
    SDL_DestroyTexture(backGround);
    SDL_DestroyTexture(fontSheet);
    delete newGameButton;
    delete loadGameButton;
    delete quitGameButton;
}
