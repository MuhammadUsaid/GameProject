#include "Room.h"
#include "Player.h"
#include "stdlib.h"

Room::Room()
{
    factory = new ObjectFactory;
    objectList = new ObjectList;
    const char* path = "Images/sprite.png";
    objects[0] = factory->getObject(BED, path, (rand() % 800) + 2, 10, 200, 100);
    objects[1] = factory->getObject(CUPBOARD, path, 10, (rand() % 500) + 100, 100, 200);
    objects[2] = factory->getObject(TABLE, path, (rand() % 400) + 300, (rand() % 200) + 300, 200, 100);
    objects[3] = factory->getObject(CHAIR, path, (objects[2]->GetX() + objects[2]->GetWidth() + 5), objects[2]->GetHeight(), 100, 100);
    objects[4] = factory->getObject(APPLE, path, rand() % 800 + 200, rand() % 500 + 200, 32, 32, 10, 15);
    objects[5] = factory->getObject(INJECTION, path, rand() % 800 + 200, rand() % 500 + 200, 32, 32, 10, 15);
    objects[6] = factory->getObject(SCISSORS, path, rand() % 800 + 200, rand() % 500 + 200, 32, 32, 10, 15);
    objects[7] = factory->getObject(APPLE, path, rand() % 800 + 200, rand() % 500 + 200, 32, 32, 10, 15);
    for(int i = 0; i < 8; i++)
    {
        objectList->Add(objects[i]);
    }
}
void Room::HandleEvents()
{

}
void Room::Update()
{

}
void Room::Render()
{
    objectList->Render();
    Player::GetInstance()->Render();
}
Room::~Room()
{
    delete factory;
    delete objectList;
    delete[] objects;
}
