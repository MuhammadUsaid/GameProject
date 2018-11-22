#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
   backGround = TextureManager::LoadTexture("Images/splash.jpg");
}

void SplashScreen::HandleEvents()
{

}
void SplashScreen::Update()
{

}
void SplashScreen::Render()
{
    SDL_RenderCopy(Game::renderer, backGround, nullptr, nullptr);
}



SplashScreen::~SplashScreen()
{
    //dtor
}
