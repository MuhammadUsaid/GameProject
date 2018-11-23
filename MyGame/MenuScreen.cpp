#include "MenuScreen.h"
#include "TextManager.h"
#include "Button.h"

MenuScreen::MenuScreen()
{
    backGround = TextureManager::LoadTexture("Images/menu.png");
    fontSheet = TextureManager::LoadTexture("Images/font.png");
    newGameButton = new Button(fontSheet, " New Game ", 500, 400);
    loadGameButton = new Button(fontSheet, "Load Game", 500, 500);
    quitGameButton = new Button(fontSheet, "Quit Game", 500, 600);
}
void MenuScreen::HandleEvents()
{

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
