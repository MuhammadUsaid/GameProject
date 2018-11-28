#include "HallScreen.h"
#include "TextManager.h"


HallScreen::HallScreen()
{
    state = 0;
    player = Player::GetInstance();
    healthBar = new Health;
    walls[0] = new GameObject("Images/wall.png", 250, 0, 10, 175);
    walls[1] = new GameObject("Images/wall.png", 800, 0, 10, 175);
    walls[2] = new GameObject("Images/wall.png", 0, 375, 250, 10); //horizontal wall
    walls[3] = new GameObject("Images/wall.png", 800, 375, 250, 10); //horizontal wall
    walls[4] = new GameObject("Images/wall.png", 250, 220, 10, 350);
    walls[5] = new GameObject("Images/wall.png", 250, 615, 10, 153);
    walls[6] = new GameObject("Images/wall.png", 800, 220, 10, 350);
    walls[7] = new GameObject("Images/wall.png", 800, 615, 10, 153);

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
    RenderWalls();
    player->Render();
}
void HallScreen::RenderWalls()
{
    for (int i = 0; i < 8; i++)
    {
        walls[i]->Render();
    }
}
HallScreen::~HallScreen()
{
    delete player;
    delete healthBar;
    delete[] walls;
}
