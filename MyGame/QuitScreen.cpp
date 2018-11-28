#include "QuitScreen.h"
#include "TextManager.h"

QuitScreen::QuitScreen()
{
    state = 0;
    running = true;
    Screen::pause = 0;
    backGround = TextureManager::LoadTexture("Images/quit.jpeg");
    fontSheet = TextureManager::LoadTexture("Images/font.png");
    newGameButton = new Button(fontSheet, " Restart ", 500, 400);
    loadGameButton = new Button(fontSheet, "Load Game", 500, 500);
    mainMenuButton = new Button(fontSheet, "Main Menu", 500, 600);
    quitGameButton = new Button(fontSheet, "Quit Game", 500, 700);
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
            onNewGame = ((newGameButton->GetX() - newGameButton->getWidth()/2) < mouseX) && ((newGameButton->GetX() + newGameButton->getWidth()/2) > mouseX)
            && ((newGameButton->GetY() - newGameButton->getHeight()/2) < mouseY && (newGameButton->GetY() + newGameButton->getHeight()/2) > mouseY);
            onLoadGame = ((loadGameButton->GetX() - loadGameButton->getWidth()/2) < mouseX) && ((loadGameButton->GetX() + loadGameButton->getWidth()/2) > mouseX)
            && ((loadGameButton->GetY() - loadGameButton->getHeight()/2) < mouseY && (loadGameButton->GetY() + loadGameButton->getHeight()/2) > mouseY);
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
                    if(onNewGame)
                    {
                        newGameButton->changeState(Clicked);
                        state = 1;
                    }
                    else if(onLoadGame)
                    {
                        loadGameButton->changeState(Clicked);
                    }
                    else if(onQuitGame)
                    {
                        quitGameButton->changeState(Clicked);
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
