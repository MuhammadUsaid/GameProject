#include "Weapon.h"
#include "TextManager.h"
#include "Player.h"
Weapon::Weapon(){}

Weapon::Weapon(const char* path, int x, int y, int width, int height, float power, int range):GameObject(path, x, y, width, height)
{
    this->power = power;
    this->range = range;
    srcRect =  {750, 370, 100, 90};
    //counter = 0;
}
void Weapon::Update()
{
    counter++;
    dstRect = Player::GetInstance()->GetRect();
}
void Weapon::SetRect(SDL_Rect rect)
{
    dstRect.x = rect.x + rect.w/4;
    dstRect.y = rect.y + rect.h/4;
    dstRect.w = rect.w/2;
    dstRect.h = rect.h/2;
}
SDL_Texture* Weapon::GetTexture()
{
    return texture;
}
SDL_Rect* Weapon::GetSrc()
{
    return &srcRect;
}
void Weapon::Render()
{
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
}

Weapon::~Weapon()
{

}
