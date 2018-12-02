#include "Doctor.h"
#include "TextManager.h"
#include <iostream>

#include "Player.h"

using namespace std;
Doctor::Doctor(int x, int y, bool up, bool down)
{
    texture = TextureManager::LoadTexture("Images/doctor.png");
    this->x = x;
    this->y = y;
    counter = y;
    exists = true;
    alive = true;
    health = 100;
    speed = 3;
    width = 40;
    height = 50;
    srcRect = {32, 78, 32, 39};
    range = 50;
    weapon = new Scalpel("Images/sprite.png",x,y,width,height,0.1,10);
    this->up = up;
    this->down = down;
    //SetClips();
}
void Doctor::Update()
{
    if (counter == 0 and up == true)
    {
        up = false;
        down = true;
    }
    if (counter + height == 768)
    {
        down = false;
        up = true;
        srcRect = {32, 0, 32, 39};
    }
    if (up)
    {
        MoveUp();
        dstRect = {x, counter, width, height};
        weapon->SetRect(dstRect);
    }
    if (counter + height <= 768 && down)
    {
        MoveDown();
        dstRect = {x, counter, width, height};
        weapon->SetRect(dstRect);
    }
    if (PlayerInRange())
    {
        Attack();
        Player::GetInstance()->DecreaseHealth(weapon->power);
    }
}
void Doctor::MoveUp()
{
    counter-=1;
}
void Doctor::MoveDown()
{
    srcRect = {32, 78, 32, 39};
    counter+=1;
}

void Doctor::Render()
{
    weapon->Render();
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);

}
bool Doctor::PlayerInRange()
{
    SDL_Rect bigRect = dstRect;
    bigRect.x -= range;
    bigRect.y -= range;
    bigRect.w += 2*range;
    bigRect.h += 2*range;
    if (CheckCollision(bigRect ,Player::GetInstance()->GetRect()) || CheckCollision(Player::GetInstance()->GetRect(), bigRect))
    {
        cout << "Attacking distance" << endl;
        return true;

    }
    return false;
}
void Doctor::Attack()
{
    weapon->Update();
}


