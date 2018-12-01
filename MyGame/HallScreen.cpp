#include "HallScreen.h"
#include "TextManager.h"
#include "Room.h"

HallScreen::HallScreen()
{
    roomNumber = 0; // 0 means we are in hallway
   // InitializeRooms();
    state = 0;
    player = Player::GetInstance();
    healthBar = new Health;
    objectList = new ObjectList;
    objectFactory = new ObjectFactory;
    backGround = TextureManager::LoadTexture("Images/hall.jpg");
    running = true;
    Screen::pause = 0;
}
void HallScreen::InitializeRooms()
{
    roomScreen[0] = new Room;
    roomScreen[1] = new Room;
    roomScreen[2] = new Room;
    roomScreen[3] = new Room;
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
                state = 1;
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
    if(player->GetHealth() <= 0)
    {
        state = 3;
    }
    switch(roomNumber)
    {
    case 1:
        roomScreen[0]->Update();
        break;
    case 2:
        roomScreen[1]->Update();
        break;
    case 3:
        roomScreen[2]->Update();
        break;
    case 4:
        roomScreen[3]->Update();
        break;
    default:
//        enemyList->Update();
        break;
    }
    player->Update();
    healthBar->Update();
}
void HallScreen::Render()
{
    switch(roomNumber)
    {
    case 1:
        roomScreen[0]->Render();
        break;
    case 2:
        roomScreen[1]->Render();
        break;
    case 3:
        roomScreen[2]->Render();
        break;
    case 4:
        roomScreen[3]->Render();
        break;
    default:
        SDL_RenderCopy(Game::renderer, backGround, nullptr, nullptr);
        //objectList->Render();
        //enemyList->Render();
        break;
    }
    healthBar->Render();
    player->Render();
}
HallScreen::~HallScreen()
{
    SDL_DestroyTexture(backGround);
    delete player;
    delete healthBar;
    delete objectList;
    delete enemyList;
    delete objectFactory;
    delete[] roomScreen;
}
