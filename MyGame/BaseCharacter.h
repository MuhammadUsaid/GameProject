#pragma once
#include "GameObject.h"

class BaseCharacter: public GameObject
{
protected:
    int health;
    int speed;
    bool alive;
public:
    BaseCharacter(){}
    int GetHealth(){ return health; }
    int GetSpeed(){ return speed; }
    void Attack();
    ~BaseCharacter(){}
};
