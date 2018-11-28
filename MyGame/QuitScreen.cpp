#include "QuitScreen.h"
#include "TextManager.h"

QuitScreen::QuitScreen()
{
    state = 0;
    running = true;
    Screen::pause = 0;
    backGround = TextureManager::LoadTexture("Images/quit.jpeg");
    fontSheet = TextureManager::LoadTexture("Images/font.png");
    newGameButton = new Button(fontSheet, " Restart ", 800, 300);
    loadGameButton = new Button(fontSheet, "Load Game", 800, 400);
    mainMenuButton = new Button(fontSheet, "Main Menu", 800, 500);
    quitGameButton = new Button(fontSheet, "Quit Game", 800, 600);
}

void QuitScreen::HandleEvents()
{
    SDL_Event e;
    bool onNewGame;
    bool onLoadGame;
    bool onMainMenu;
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
            onMainMenu = ((mainMenuButton->GetX() - mainMenuButton->GetWidth()/2) < mouseX) && ((mainMenuButton->GetX() + mainMenuButton->GetWidth()/2) > mouseX)
            && ((mainMenuButton->GetY() - mainMenuButton->GetHeight()/2) < mouseY && (mainMenuButton->GetY() + mainMenuButton->GetHeight()/2) > mouseY);
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
                    else if(onMainMenu)
                    {
                        state = 2;
                    }
                }
                break;
            }
        }
}
void QuitScreen::Update()
{

}
void QuitScreen::Render()
{
    SDL_RenderCopy(Game::renderer, backGround, nullptr, nullptr);
    newGameButton->Render();
    loadGameButton->Render();
    mainMenuButton->Render();
    quitGameButton->Render();
}
QuitScreen::~QuitScreen()
{
    SDL_DestroyTexture(backGround);
    SDL_DestroyTexture(fontSheet);
    delete newGameButton;
    delete loadGameButton;
    delete mainMenuButton;
    delete quitGameButton;
}
