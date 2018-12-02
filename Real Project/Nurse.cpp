#include "Nurse.h"
#include "TextManager.h"
#include <iostream>
#include "Player.h"
using namespace std;
Nurse::Nurse(int x, int y, bool left, bool right)
{
    texture = TextureManager::LoadTexture("Images/Nurse Sprite.png");
    this->x = x;
    this->y = y;
    this->left = left;
    this->right = right;
    counter = x;
    alive = true;
    exists = true;
    health = 100;
    speed = 3;
    width = 50;
    height = 50;
    srcRect = {0, 96, 32, 48};
    range = 50;
    weapon = new Injection("Images/sprite.png",x,y,width,height,0.2,10);


    //left = false;
    //right = true;
    //SetClips();
}
void Nurse::Update()
{
    if (counter == 0 and left == true)
    {
        left = false;
        right = true;
    }
    if (counter + height == 1024)
    {
        right = false;
        left = true;
        srcRect = {0, 48, 32, 48};
        //MoveUp();
        //dstRect = {x, counter, width, height};
    }
    if (left)
    {

        MoveLeft();
        dstRect = {counter, y, width, height};
        //dstRect2 = {950, counter, width, height};
        weapon->SetRect(dstRect);
    }
    if (counter + height <= 1024 && right)
    {
        //cout<<"here"<<endl;
        MoveRight();
        dstRect = {counter, y, width, height};
        //dstRect2 = {800, counter, width, height};
        weapon->SetRect(dstRect);
    }
    if (PlayerInRange())
    {
        //weapon->Render();
        //weapon->Update(player);
        Attack();
        Player::GetInstance()->DecreaseHealth(weapon->power);

    }
}
void Nurse::MoveLeft()
{
    //cout<<"here"<<endl;
    counter-=1;
}
void Nurse::MoveRight()
{
    srcRect = {0, 96, 32, 48};
    counter+=1;  //change speed
}
//bool Nurse::PointInRect(int x, int y, SDL_Rect rec)
//{
//    if (x >= rec.x && y >= rec.y && x <= (rec.x + rec.w) && y <= (rec.y + rec.h))
//    {
//        return true;
//    }
//    return false;
//}
//bool Nurse::CheckCollision(SDL_Rect r1, SDL_Rect r2)
//{
//    if(PointInRect(r1.x, r1.y, r2) == true || PointInRect(r1.x + r1.w, r1.y, r2) == true ||
//        PointInRect(r1.x , r1.y + r1.h, r2) == true || PointInRect(r1.x + r1.w, r1.y + r1.h, r2) == true)
//    {
//        return true;
//    }
//    return false;
//}

void Nurse::Render()
{
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
    weapon->Render();
}
void Nurse::Attack()
{
    weapon->Update();
}

bool Nurse::PlayerInRange()
{
    SDL_Rect bigRect = dstRect;
    bigRect.x -= range;
    bigRect.y -= range;
    bigRect.w += 2*range;
    bigRect.h += 2*range;
    if (CheckCollision(bigRect ,Player::GetInstance()->GetRect()) || CheckCollision(Player::GetInstance()->GetRect(),bigRect))
    {
        cout << "Attacking distance" << endl;
        return true;

    }
    return false;
}

