#include "Game.h"
#include <SDL2/SDL_image.h>
#include "SplashScreen.h"
#include "MenuScreen.h"
#include "HallScreen.h"

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{
    width = 1024;
    height = 768;
    Init();
    //ShowSplash();
    currentScreen = new HallScreen;
}

/****Method To Initialize Everything and show error if something fails****/

void Game::Init()
{
    running = false;
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) //Initializing SDL
    {
        cerr << "SDL Not Initialized! " << SDL_GetError() << endl;
        return;
    }
    if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG || IMG_Init(IMG_INIT_JPG) != IMG_INIT_JPG) //Initializing Image
    {
        cerr << "Image Not Initialized! " << IMG_GetError() << endl;
        return;
    }
    window = SDL_CreateWindow("Hospital Ka Qaidi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, false);
    if(window == nullptr)
    {
        cerr << "Window Not Created! " << SDL_GetError() << endl;
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer == nullptr)
    {
        cerr << "Renderer Not Created! " << SDL_GetError() << endl;
        return;
    }
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    running = true;
}

/*** Get Running State ***/
bool Game::isRunning()
{
    return running;
}
/** Show Splash Screen for 5 seconds **/
void Game::ShowSplash()
{
    SplashScreen splash;
    SDL_RenderClear(Game::renderer);
    splash.Render();
    SDL_RenderPresent(Game::renderer);
    SDL_Delay(3000);
}

/**** Method To Handle Events ****/

void Game::HandleEvents()
{
    currentScreen->HandleEvents();
    running = currentScreen->isRunning();
}
void Game::Update()
{
    currentScreen->Update();
}

/**** Method To Render All The Objects On Screen ****/

void Game::Render()
{
    SDL_RenderClear(renderer);
    currentScreen->Render();
    SDL_RenderPresent(renderer);
}

Game::~Game()
{
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_Quit();
    delete currentScreen;
}

