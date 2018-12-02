#include "Sister.h"
#include "TextManager.h"

Sister::Sister(){}
Sister::Sister(int x, int y)
{
    texture = TextureManager::LoadTexture("Images/Sister.png");
    srcRect = {100, 0, 50, 50};
    this->x = x;
    this->y = y;
    dstRect = {x, y, 50, 50};
}
void Sister::Render()
{
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
}
Sister::~Sister()
{
    SDL_DestroyTexture(texture);
}
