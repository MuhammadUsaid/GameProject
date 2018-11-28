#include "SplashScreen.h"
#include "TextManager.h"

SplashScreen::SplashScreen()
{
    backGround = TextureManager::LoadTexture("Images/splash.jpg");
}

void SplashScreen::Update()
{

}
void SplashScreen::Render()
{
    SDL_RenderCopy(Game::renderer, backGround, nullptr, nullptr);
}
void SplashScreen::HandleEvents()
{

}
SplashScreen::~SplashScreen()
{
    SDL_DestroyTexture(backGround);
}
