#pragma once
#include "Screen.h"
#include "Player.h"
#include "Health.h"
#include "ObjectList.h"
#include "Doctor.h"
#include "Nurse.h"
#include "ObjectFactory.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include "Door.h"
#include "Room.h"
#include "Inventory.h"

class HallScreen: public Screen
{
private:
    Player* player; //Our Main character which is a singleton
    Health* healthBar; //Health Bar of Player
    int roomNumber; //This number will us which room we are in
    Room* roomScreen[4]; // Different screens for 4 rooms
    ObjectList* enemyList; // A list of Enemies
    ObjectList* doorList; // A list of doors
    ObjectFactory* objectFactory; //Object Factory to create weapons and enemies in hallway
    GameObject* objects[5]; //All the weapons in this array of pointers
    GameObject* enemies[6]; //All the enemies
    Inventory* inventory;
    void AddDoors(); //Method of Adding the objects to the list
    void AddEnemies(); //Method of Adding the enemies to the list
    void InitializeRooms(); // A Method to initialize room screens
    Doctor* doctor1;
    Doctor* doctor2;
    Doctor* doctor3;
    Nurse* nurse1;
    Nurse* nurse2;
    Nurse* nurse3;
    GameObject* door[4];
public:
    HallScreen();
    void HandleEvents();
    void Render();
    void Update();
    ~HallScreen();
    int GetPlayerX();
    int GetPlayerY();
    float GetPlayerHealth();
    void SaveHallScreen();
    void LoadHallScreen();
};
