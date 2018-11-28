#include "HallScreen.h"

HallScreen::HallScreen()
{
    state = 0;
    player = Player::GetInstance();
    running = true;
    Screen::pause = 0;
}

void HallScreen::HandleEvents()
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        switch(e.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            switch(e.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                state = 3;
                break;
            case SDLK_p:
                Screen::pause = 1;
                break;
            case SDLK_UP:
                player->MoveUp();
                break;
            case SDLK_DOWN:
                player->MoveDown();
                break;
            case SDLK_RIGHT:
                player->MoveRight();
                break;
            case SDLK_LEFT:
                player->MoveLeft();
                break;
            }
        break;
        }
    }
}
void HallScreen::Update()
{
    player->Update();
}
void HallScreen::Render()
{
    player->Render();
}
HallScreen::~HallScreen()
{
    delete player;
}
