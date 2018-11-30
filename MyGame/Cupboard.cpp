#include "Cupboard.h"
#include "TextManager.h"

Cupboard::Cupboard()
{

}

Cupboard::Cupboard(const char* path, int x, int y, int width, int height):GameObject(path, x, y, width, height)
{
    srcRect = {725, 520, 150, 150};
    type = CUPBOARD;
}

void Cupboard::Render()
{
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
}
