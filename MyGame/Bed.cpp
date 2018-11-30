#include "Bed.h"
#include "TextManager.h"

Bed::Bed()
{
    srcRect = {0, 0, 925/3, 864/3};
}
Bed::Bed(const char* path, int x, int y, int width, int height):GameObject(path, x, y, width, height)
{
    srcRect = {0, 0, 925/3, 864/3};
    type =  BED;
}

void Bed::Render()
{
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
}
