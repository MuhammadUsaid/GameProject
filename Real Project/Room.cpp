#include "Room.h"
#include "stdlib.h"

Room::Room(int number)
{
//    state = 0;
    factory = new ObjectFactory;
    objectList = new ObjectList;
    const char* path = "Images/sprite.png";
    objects[0] = factory->getObject(APPLE, path, rand() % 800 + 200, rand() % 500 + 200, 32, 32, 10, 15);
    objects[1] = factory->getObject(INJECTION, path, rand() % 800 + 200, rand() % 500 + 200, 32, 32, 10, 15);
    objects[2] = factory->getObject(SCALPEL, path, rand() % 800 + 200, rand() % 500 + 200, 32, 32, 10, 15);
    objects[3] = factory->getObject(APPLE, path, rand() % 800 + 200, rand() % 500 + 200, 32, 32, 10, 15);
    objects[4] = factory->getObject(BED, path, (rand() % 800) + 2, 10, 200, 100);
    objects[5] = factory->getObject(CUPBOARD, path, 10, (rand() % 500) + 100, 100, 200);
    objects[6] = factory->getObject(TABLE, path, (rand() % 400) + 300, (rand() % 200) + 300, 200, 100);
    objects[7] = factory->getObject(CHAIR, path, (objects[2]->GetX() + objects[2]->GetWidth() + 5), objects[2]->GetHeight(), 100, 100);
    switch(number)
    {
    case 1:
        objects[8] = factory->getObject(DOOR, "Images/door.png", 960, 600, 50, 100);
        break;
    case 2:
        objects[8] = factory->getObject(DOOR, "Images/door.png", 960, 600, 50, 100);
        break;
    case 3:
        objects[8] = factory->getObject(DOOR, "Images/door.png", 10, 600, 50, 100);
        break;
    case 4:
        objects[8] = factory->getObject(DOOR, "Images/door.png", 10, 600, 50, 100);
        break;
    }
    for(int i = 0; i < 9; i++)
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
}
Room::~Room()
{
    delete factory;
    delete objectList;
    for(int i = 0; i < 9; i++)
    {
        delete objects[i];
    }
}
