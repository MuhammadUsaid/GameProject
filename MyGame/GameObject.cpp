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
    dstRect = {x, y, width, height};
}
SDL_Rect GameObject::GetRect()
{
    return dstRect;
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
