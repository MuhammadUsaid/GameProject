#pragma once
#include "Screen.h"
#include "Player.h"
#include "Health.h"
#include "ObjectList.h"
#include "Bed.h"
#include "Cupboard.h"
#include "Chair.h"
#include "Table.h"
#include "ObjectFactory.h"
#include <iostream>

class HallScreen: public Screen
{
private:
    Player* player; //Our Main character which is a singleton
    Health* healthBar; //Health Bar of Player
    int roomNumber; //This number will us which room we are in
    Screen* roomScreen[4]; // Different screens for 4 rooms
    ObjectList* objectList; // A list of objects
    ObjectList* enemyList; // A list of Enemies
    ObjectFactory* objectFactory; //Object Factory to create weapons and enemies in hallway
    GameObject* objects[5]; //All the weapons in this array of pointers
    void AddObjects(); //Method of Adding the objects to the list
    void InitializeRooms(); // A Method to initialize room screens
public:
    HallScreen();
    void HandleEvents();
    void Render();
    void Update();
    ~HallScreen();
};
