#include "Game.h"
#include <SDL2/SDL_image.h>
#include "SplashScreen.h"
#include "MenuScreen.h"
#include "HallScreen.h"
#include "QuitScreen.h"
#include "PauseScreen.h"

SDL_Renderer* Game::renderer = nullptr;
int Screen::pause = 0;
Game::Game()
{
    state = 0;
    width = 1024;
    height = 768;
    Init();
    //ShowSplash();
    currentScreen = new HallScreen;
    pauseScreen = nullptr;
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
    if(pauseScreen == nullptr)
    {
        currentScreen->HandleEvents();
        running = currentScreen->IsRunning();
        state = currentScreen->GetState();
    }
    else
    {
        pauseScreen->HandleEvents();
        running = pauseScreen->IsRunning();
        state = pauseScreen->GetState();
    }
}
void Game::Update()
{
    switch(state)
    {
    case 1:
        delete currentScreen;
        currentScreen = new HallScreen;
        break;
    case 2:
        delete currentScreen;
        delete pauseScreen;
        pauseScreen = nullptr;
        currentScreen = new MenuScreen;
        break;
    case 3:
        delete currentScreen;
        currentScreen = new QuitScreen;
    default:
        if(Screen::pause == 0)
        {
            currentScreen->Update();
        }
        else if(Screen::pause == 1)
        {
            pauseScreen = new PauseScreen;
        }
        else if(Screen::pause == 2)
        {
            delete pauseScreen;
            pauseScreen = nullptr;
            Screen::pause = 0;
        }
    }
}

/**** Method To Render All The Objects On Screen ****/

void Game::Render()
{
    SDL_RenderClear(renderer);
    currentScreen->Render();
    if(pauseScreen != nullptr)
    {
        pauseScreen->Render();
    }
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
    delete pauseScreen;
}

