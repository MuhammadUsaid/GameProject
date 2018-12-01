#pragma once
#include"GameObject.h"
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
    //GameObject Remove();
    void Render();
};

/*
int GameObject::GameObject()
{
    int value = -1;
    if(head != NULL)
    {
        Node* temp = head;
        value = head->data;
        head = head->next;
        delete temp;
        //head->prev = NULL; //Why will this code cause a crash?
    }
    return value;
}
*/



