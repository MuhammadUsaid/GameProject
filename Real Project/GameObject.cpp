#include "GameObject.h"
#include "TextManager.h"

GameObject::GameObject(){}
GameObject::GameObject(const char* path, int x, int y, int width, int height)
{
    texture = TextureManager::LoadTexture(path);
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    exists = true;
    dstRect = {x, y, width, height};
}
SDL_Rect GameObject::GetRect()
{
    return dstRect;
}
int GameObject::GetX()
{
    return x;
}
int GameObject::GetY()
{
    return y;
}
int GameObject::GetWidth()
{
    return width;
}
int GameObject::GetHeight()
{
    return height;
}
bool GameObject::GetExistence()
{
    return exists;
}
int GameObject::GetType()
{
    return type;
}
bool GameObject::GetKeyState(){ return true; }
void GameObject::SetKeyState(bool x){ }
void GameObject::SetX(int x)
{
    this->x = x;
}
void GameObject::SetExistence(bool a)
{
    exists = a;
}
SDL_Texture* GameObject::GetTexture(){ return texture; }
SDL_Rect* GameObject::GetSrc(){ return &srcRect; }
void GameObject::SetY(int y)
{
    this->y = y;
}
void GameObject::Update()
{

}
void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, texture, nullptr, &dstRect);
}
GameObject::~GameObject()
{
    SDL_DestroyTexture(texture);
}
bool GameObject::PointInRect(int x, int y, SDL_Rect rec)
{
    if (x >= rec.x && y >= rec.y && x <= (rec.x + rec.w) && y <= (rec.y + rec.h))
    {
        return true;
    }
        return false;
}
bool GameObject::CheckCollision(SDL_Rect r1, SDL_Rect r2)
{
    if(PointInRect(r1.x, r1.y, r2) == true || PointInRect(r1.x + r1.w, r1.y, r2) == true ||
        PointInRect(r1.x , r1.y + r1.h, r2) == true || PointInRect(r1.x + r1.w, r1.y + r1.h, r2) == true)
    {
        return true;
    }
    return false;
}
