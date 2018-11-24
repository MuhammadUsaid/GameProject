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
    void Attack();
    ~BaseCharacter(){}
};
