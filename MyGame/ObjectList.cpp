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
        //cout<<"Deallocating value: "<<temp->data<<endl;
        delete temp;
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
    Node* temp = head;
    while(temp!=NULL)
    {
        //cout<<"here"<<endl;
        temp->data->Render();
        //cout<<"Value: "<<temp->data<<endl;
        temp=temp->next;
    }
}
