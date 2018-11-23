#include "MenuScreen.h"
#include "TextManager.h"

MenuScreen::MenuScreen()
{
    backGround = TextureManager::LoadTexture("Images/menu.png");
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
}
MenuScreen::~MenuScreen()
{
    SDL_DestroyTexture(backGround);
}
