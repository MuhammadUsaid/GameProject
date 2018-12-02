#pragma once
#include"GameObject.h"
#include "Player.h"

struct Node
{
    GameObject* data;
    Node* next;
};

class ObjectList
{
private:
    Node* head;
    Node* tail;
    int length;
public:
    ObjectList();
    ~ObjectList();
    void Add(GameObject*);
    int GetLength();
    void Render();
    bool CheckListCollision(SDL_Rect,Player*);
};




