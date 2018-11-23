#include "MenuScreen.h"
#include "TextManager.h"
#include "Button.h"

MenuScreen::MenuScreen()
{
    running = true;
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
        onNewGame = ((newGameButton->GetX() - newGameButton->getWidth()/2) < mouseX) && ((newGameButton->GetX() + newGameButton->getWidth()/2) > mouseX)
        && ((newGameButton->GetY() - newGameButton->getHeight()/2) < mouseY && (newGameButton->GetY() + newGameButton->getHeight()/2) > mouseY);
        onLoadGame = ((loadGameButton->GetX() - loadGameButton->getWidth()/2) < mouseX) && ((loadGameButton->GetX() + loadGameButton->getWidth()/2) > mouseX)
        && ((loadGameButton->GetY() - loadGameButton->getHeight()/2) < mouseY && (loadGameButton->GetY() + loadGameButton->getHeight()/2) > mouseY);
        onQuitGame = ((quitGameButton->GetX() - quitGameButton->getWidth()/2) < mouseX) && ((quitGameButton->GetX() + quitGameButton->getWidth()/2) > mouseX)
        && ((quitGameButton->GetY() - quitGameButton->getHeight()/2) < mouseY && (quitGameButton->GetY() + quitGameButton->getHeight()/2) > mouseY);
        switch(e.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_MOUSEMOTION:
            if(onNewGame)
            {
                newGameButton->changeState(Hover);
            }
            else
            {
                newGameButton->changeState(Normal);
                if(onLoadGame)
                {
                    loadGameButton->changeState(Hover);
                }
                else
                {
                    loadGameButton->changeState(Normal);
                    if(onQuitGame)
                    {
                        quitGameButton->changeState(Hover);
                    }
                    else
                    {
                        quitGameButton->changeState(Normal);
                    }
                }

            }

            break;
        case SDL_MOUSEBUTTONDOWN:
            if(e.button.button == SDL_BUTTON_LEFT)
            {
                if(onNewGame)
                {
                    newGameButton->changeState(Clicked);
                }
                else if(onLoadGame)
                {
                    loadGameButton->changeState(Clicked);
                }
                else if(onQuitGame)
                {
                    quitGameButton->changeState(Clicked);
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
