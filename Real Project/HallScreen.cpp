#include "HallScreen.h"
#include "TextManager.h"
#include "Room.h"

HallScreen::HallScreen()
{
    roomNumber = 0; // 0 means we are in hallway
    InitializeRooms();
    state = 0;
    player = Player::GetInstance();
    healthBar = new Health;
    enemyList = new ObjectList;
    doorList = new ObjectList;
    objectFactory = new ObjectFactory;
    inventory = new Inventory;
    backGround = TextureManager::LoadTexture("Images/bg.jpeg");
    running = true;
    Screen::pause = 0;
    doctor1 = new Doctor(10,0,false,true);
    doctor2 = new Doctor(500,718,true,false);
    doctor3 = new Doctor(900,0,false,true);
    nurse1 = new Nurse(980,10,true,false);
    nurse2 = new Nurse(0,350,false,true);
    nurse3 = new Nurse(980,718,true, false);
    door[0] = new Door("Images/door.png", 0, 0, 70, 150);
    door[1] = new Door("Images/door.png", 0, 600, 70, 150);
    door[2] = new Door("Images/door.png", 950, 0, 70, 150);
    door[3] = new Door("Images/door.png", 950, 600, 70, 150);
    AddDoors();
    AddEnemies();
}
void HallScreen::AddDoors()
{
    for(int i = 0; i < 4; i++)
    {
        doorList->Add(door[i]);
    }
}
void HallScreen::InitializeRooms()
{
    roomScreen[0] = new Room(1);
    roomScreen[1] = new Room(2);
    roomScreen[2] = new Room(3);
    roomScreen[3] = new Room(4);
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
            if (enemyList->CheckListCollision(player->GetRect(),player))
            {
                switch(e.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    Screen::pause = 1;
                    break;
                case SDLK_p:
                    Screen::pause = 1;
                    break;
                case SDLK_UP:
                    if (!player->Bottom)
                    {
                        player->MoveUp();
                        break;
                    }
                case SDLK_DOWN:
                    if (!player->Top)
                    {
                        player->MoveDown();
                        break;
                    }
                case SDLK_RIGHT:
                    if (!player->Left)
                    {
                        player->MoveLeft();
                        break;
                    }
                case SDLK_LEFT:
                    if (!player->Right)
                    {
                        player->MoveRight();
                        break;
                    }
                }
            }
            else if( roomNumber == 0 && doorList->CheckListCollision(player->GetRect(),player))
            {
                switch(e.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    Screen::pause = 1;
                    break;
                case SDLK_p:
                    Screen::pause = 1;
                    break;
                case SDLK_LEFT:
                    if(player->collidingWith == door[0])
                    {
                        roomNumber = 1;
                    }
                    else if(player->collidingWith == door[1])
                    {
                        roomNumber = 2;
                    }
                    else
                    {
                        player->MoveLeft();
                    }
                    break;
                case SDLK_RIGHT:
                    if(player->collidingWith == door[2])
                    {
                        roomNumber = 3;
                    }
                    else if(player->collidingWith == door[3])
                    {
                        roomNumber = 4;
                    }
                    else
                    {
                        player->MoveLeft();
                    }
                    break;
                }
            }
            else
            {
                switch(e.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    Screen::pause = 1;
                    break;
                case SDLK_p:
                    Screen::pause = 1;
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
                case SDLK_UP:
                    player->MoveUp();
                    break;
                case SDLK_s:
                    SaveHallScreen();
                    break;
                case SDLK_l:
                    LoadHallScreen();
                    break;
                }
            }
        }
        break;
    }
    if(player->GetHealth() <= 0)
    {
        state = 3;
    }
}

void HallScreen::Update()
{
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
    doctor1->Update();
    doctor2->Update();
    doctor3->Update();
    nurse1->Update();
    nurse2->Update();
    nurse3->Update();
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
        doorList->Render();
        //objectList->Render();
        //enemyList->Render();
        break;
    }
    healthBar->Render();
    player->Render();
    enemyList->Render();
    inventory->Render();
}
HallScreen::~HallScreen()
{
    SDL_DestroyTexture(backGround);
    delete player;
    delete healthBar;
    delete inventory;
    delete enemyList;
    delete doorList;
    delete objectFactory;
    for(int i = 0; i < 4; i++)
    {
        delete roomScreen[i];
    }
    delete doctor1;
    delete doctor2;
    delete doctor3;
    delete nurse1;
    delete nurse2;
    delete nurse3;
}
void HallScreen::SaveHallScreen()
{
    ofstream file;
    file.open("HallScreenData.csv");
    file << player->GetX() << "\n";
    file << player->GetY() << "\n";
    file << GetPlayerHealth() << "\n";
    file << doctor1->GetRect().x << "\n";
    file << doctor1->GetRect().y << "\n";
    file << doctor2->GetRect().x << "\n";
    file << doctor2->GetRect().y << "\n";
    file << nurse1->GetRect().x << "\n";
    file << nurse1->GetRect().y << "\n";
    file << nurse2->GetRect().x << "\n";
    file << nurse2->GetRect().y << "\n";
    file << nurse1->left << "\n";
    file << nurse1->right << "\n";
    file << nurse2->left << "\n";
    file << nurse2->right << "\n";
    file << doctor1->up << "\n";
    file << doctor1->down << "\n";
    file << doctor2->up << "\n";
    file << doctor2->down << "\n";
    file << doctor3->GetRect().x << "\n";
    file << doctor3->GetRect().y << "\n";
    file << doctor3->up<<"\n";
    file << doctor3->down<<"\n";
    file << nurse3->GetRect().x << "\n";
    file << nurse3->GetRect().y << "\n";
    file << nurse3->left<<"\n";
    file << nurse3->right<<"\n";
}
void HallScreen::AddEnemies()
{
    enemyList->Add(doctor1);
    enemyList->Add(doctor2);
    enemyList->Add(doctor3);
    enemyList->Add(nurse1);
    enemyList->Add(nurse2);
    enemyList->Add(nurse3);
}
void HallScreen::LoadHallScreen()
{
    ifstream file ("HallScreenData.csv");
    string line1,line2,line3;
    getline(file,line1);
    getline(file,line2);
    getline(file,line3);
    player->SetX(atoi(line1.c_str()));
    player->SetY(atoi(line2.c_str()));
    player->SetHealth(stof(line3.c_str()));
    getline(file,line1);
    getline(file,line2);
    getline(file,line3);
    doctor1->SetX(atoi(line1.c_str()));
    doctor1->SetY(atoi(line2.c_str()));
    doctor2->SetX(atoi(line3.c_str()));
    getline(file,line1);
    getline(file,line2);
    getline(file,line3);
    doctor2->SetY(atoi(line1.c_str()));
    nurse1->SetX(atoi(line2.c_str()));
    nurse1->SetX(atoi(line3.c_str()));
    getline(file,line1);
    getline(file,line2);
    nurse2->SetX(atoi(line1.c_str()));
    nurse2->SetX(atoi(line2.c_str()));
    getline(file,line1);
    getline(file,line2);
    getline(file,line3);
    nurse1->left = atoi(line1.c_str());
    nurse1->right = atoi(line2.c_str());
    nurse2->left = atoi(line3.c_str());
    getline(file,line1);
    getline(file,line2);
    getline(file,line3);
    nurse2->right = atoi(line1.c_str());
    doctor1->up = atoi(line2.c_str());
    doctor1->down= atoi(line3.c_str());
    getline(file,line1);
    getline(file,line2);
    doctor2->up = atoi(line1.c_str());
    doctor2->down = atoi(line2.c_str());
    getline(file,line1);
    getline(file,line2);
    getline(file,line3);
    doctor3->SetX(atoi(line1.c_str()));
    doctor3->SetY(atoi(line2.c_str()));
    doctor3->up = atoi(line3.c_str());
    getline(file,line1);
    getline(file,line2);
    getline(file,line3);
    doctor3->down = atoi(line1.c_str());
    nurse3->SetX(atoi(line2.c_str()));
    nurse3->SetY(atoi(line3.c_str()));
    getline(file,line1);
    getline(file,line2);
    nurse3->left = atoi(line1.c_str());
    nurse3->right = atoi(line2.c_str());
}
float HallScreen::GetPlayerHealth()
{
    return player->GetHealth();
}
