#include "Weapon.h"
#include "TextManager.h"

Weapon::Weapon(){}

Weapon::Weapon(const char* path, int x, int y, int width, int height, int power, int range):GameObject(path, x, y, width, height)
{
    this->power = power;
    this->range = range;
    srcRect =  {750, 370, 100, 90};
}
void Weapon::Update()
{

}
//void Weapon::SetDstRect(int x, int y, int w, int h)
//{
//    dstRect = {x, y, w, h};
//}
void Weapon::Render()
{
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
}

Weapon::~Weapon()
{

}
