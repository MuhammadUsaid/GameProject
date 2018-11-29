#include "HallScreen.h"
#include "TextManager.h"


HallScreen::HallScreen()
{
    state = 0;
    player = Player::GetInstance();
    healthBar = new Health;
    objList = new ObjectList;
    InitializeWalls();
    InitializeChairs();
    InitializeBeds();
    InitializeCupboards();
    AddObjects();
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
    objList->Render();
    player->Render();
}
void HallScreen::InitializeCupboards()
{
    cupboards[0] = new Cupboard("Images/sprite.png", 0, 200, 32, 45);
    cupboards[1] = new Cupboard("Images/sprite.png", 980, 200, 32, 45);
    cupboards[2] = new Cupboard("Images/sprite.png", 0, 600, 32, 45);
    cupboards[3] = new Cupboard("Images/sprite.png", 980, 600, 32, 45);
}
void HallScreen::InitializeChairs()
{
    chairs[0] = new Chair("Images/sprite.png", 100, 200, 32, 32);
    chairs[1] = new Chair("Images/sprite.png", 900, 200, 32, 32);
    chairs[2] = new Chair("Images/sprite.png", 100, 600, 32, 32);
    chairs[3] = new Chair("Images/sprite.png", 900, 600, 32, 32);
}
void HallScreen::InitializeBeds()
{
    beds[0] = new Bed("Images/sprite.png", 45,10, 40, 40);
    beds[1] = new Bed("Images/sprite.png", 45,400, 40, 40);
    beds[2] = new Bed("Images/sprite.png", 850,10, 40, 40);
    beds[3] = new Bed("Images/sprite.png", 859,400, 40, 40);
}
void HallScreen::InitializeWalls()
{
    walls[0] = new GameObject("Images/wall.png", 250, 0, 10, 175);
    walls[1] = new GameObject("Images/wall.png", 800, 0, 10, 175);
    walls[2] = new GameObject("Images/wall.png", 0, 375, 250, 10); //horizontal wall
    walls[3] = new GameObject("Images/wall.png", 800, 375, 250, 10); //horizontal wall
    walls[4] = new GameObject("Images/wall.png", 250, 220, 10, 350);
    walls[5] = new GameObject("Images/wall.png", 250, 615, 10, 153);
    walls[6] = new GameObject("Images/wall.png", 800, 220, 10, 350);
    walls[7] = new GameObject("Images/wall.png", 800, 615, 10, 153);
}
void HallScreen::AddObjects()
{
    for (int i = 0; i < 8; i++)
    {
        objList->Add(walls[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        objList->Add(beds[i]);
        objList->Add(cupboards[i]);
        objList->Add(chairs[i]);
    }
}
HallScreen::~HallScreen()
{
    delete player;
    delete healthBar;
    delete objList;
}
