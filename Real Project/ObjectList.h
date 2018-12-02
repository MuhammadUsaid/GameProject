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
    void Update();
    bool CheckListCollision(SDL_Rect,Player*);
    /** Helper Functions **/
    bool PointInRectHelper(int x, int y, SDL_Rect rec);
    bool CheckCollisionHelper(SDL_Rect r1, SDL_Rect r2);
    bool CheckRight(SDL_Rect obj,  SDL_Rect player);
    bool CheckLeft(SDL_Rect obj, SDL_Rect player);
    bool CheckBottom(SDL_Rect obj, SDL_Rect player);
    bool CheckTop(SDL_Rect obj, SDL_Rect player);
};




