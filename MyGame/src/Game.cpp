#include "Game.h"
#include <SDL2/SDL_image.h>

SDL_Renderer* Game::renderer = nullptr;
//Screen* Game::currentScreen = nullptr;

/** Setting the width and height **/
int Game::width = 1024;
int Game::height = 768;

Game::Game()
{
    Init();
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
    ShowSplash();
    //currentScreen = new MenuScreen;
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
    SDL_Event e;
    SDL_PollEvent(&e);
    switch(e.type)
    {
    case SDL_QUIT:
        running = false;
        break;
    case SDL_MOUSEBUTTONDOWN:
        break;
    case SDL_KEYDOWN:
        switch(e.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            running = false;
            break;
        case SDLK_UP:
            //one->MoveUp();
            break;
        case SDLK_DOWN:
            //one->MoveDown();
            break;
        case SDLK_RIGHT:
            //one->MoveRight();
            break;
        case SDLK_LEFT:
            //one->MoveLeft();
            break;
        }
        break;
    case SDL_KEYUP:
        switch(e.key.keysym.sym)
        {
        case SDLK_UP:
            break;
        }
    default:
        break;
    }
}

void Game::Update()
{

}

/**** Method To Render All The Objects On Screen ****/

void Game::Render()
{
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

Game::~Game()
{
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_Quit();
}
