#include "HallScreen.h"
#include "TextManager.h"


HallScreen::HallScreen()
{
    state = 0;
    player = Player::GetInstance();
    healthBar = new Health;
    backGround = TextureManager::LoadTexture("Images/hall.jpg");
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
    healthBar->Update();
}
void HallScreen::Render()
{
    SDL_RenderCopy(Game::renderer, backGround, nullptr, nullptr);
    healthBar->Render();
    player->Render();
}
HallScreen::~HallScreen()
{
    delete player;
    delete healthBar;
}
