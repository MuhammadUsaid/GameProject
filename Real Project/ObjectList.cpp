#include"ObjectList.h"
using namespace std;

ObjectList::ObjectList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

ObjectList::~ObjectList()
{
    while(head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        if(!temp->data->isInPlayer)
        {
            delete temp;
        }
    }
}
int ObjectList::GetLength()
{
    return length;
}
void ObjectList::Add(GameObject* value)
{
    length++;
    if(head == NULL)
    {
        head = new Node;
        head->data = value;
        head->next = NULL;
        tail = head;
    }
    else
    {
        tail->next = new Node;
        tail->next->data = value;
        tail->next->next = NULL;
        tail = tail->next;
    }
}
void ObjectList::Render()
{
    if(head != NULL)
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            if(temp->data->GetExistence())
            {
                temp->data->Render();
            }
            temp=temp->next;
        }
    }
}
void ObjectList::Update()
{
    if(head != NULL)
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            if(temp->data->GetExistence())
            {
                temp->data->Update();
            }
            temp=temp->next;
        }
    }
}
bool ObjectList::PointInRectHelper(int x, int y, SDL_Rect rec)
{
    if (x >= rec.x && y >= rec.y && x <= (rec.x + rec.w) && y <= (rec.y + rec.h))
    {
        return true;
    }
    return false;
}
bool ObjectList::CheckCollisionHelper(SDL_Rect r1, SDL_Rect r2)
{
    r1.x = r1.x + r1.w/3;
    r1.w = r1.w/3;
    r1.y = r1.y + r1.h/3;
    r1.h = r1.h/3;
    if(PointInRectHelper(r1.x, r1.y, r2) == true || PointInRectHelper(r1.x + r1.w, r1.y, r2) == true ||
        PointInRectHelper(r1.x , r1.y + r1.h, r2) == true || PointInRectHelper(r1.x + r1.w, r1.y + r1.h, r2) == true)
    {
        return true;
    }
    return false;
}
bool ObjectList::CheckRight(SDL_Rect obj,  SDL_Rect player)
{
    if (player.x > obj.x && player.x + player.w > obj.x + obj.w)
        return true;
    return false;
}
bool ObjectList::CheckLeft(SDL_Rect obj, SDL_Rect player)
{
    if (player.x < obj.x && player.x + player.w < obj.x + obj.w)
        return true;
    return false;
}
bool ObjectList::CheckBottom(SDL_Rect obj, SDL_Rect player)
{
    if (player.y + player.h > obj.y + obj.h && player.y > obj.y)
        return true;
    return false;
}
bool ObjectList::CheckTop(SDL_Rect obj, SDL_Rect player)
{
    if (player.y + player.h < obj.y + obj.h && player.y < obj.y)
        return true;
    return false;
}


bool ObjectList::CheckListCollision(SDL_Rect player, Player* playerObj)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data->GetExistence())
        {
            if (CheckCollisionHelper(temp->data->GetRect(),player) || CheckCollisionHelper(player, temp->data->GetRect()))
            {
                playerObj->Top = CheckTop(temp->data->GetRect(),player);
                playerObj->Bottom = CheckBottom(temp->data->GetRect(),player);
                playerObj->Left = CheckLeft(temp->data->GetRect(),player);
                playerObj->Right = CheckRight(temp->data->GetRect(),player);
                playerObj->collidingWith = temp->data;
                return true;
            }
        }
        temp=temp->next;
    }
    return false;
}
