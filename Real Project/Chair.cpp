#include "Chair.h"
#include "TextManager.h"

Chair::Chair()
{

}

Chair::Chair(const char* path, int x, int y, int width, int height):GameObject(path, x, y, width, height)
{
    srcRect = {430, 290, 150, 280};
    type = CHAIR;
}

void Chair::Render()
{
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
}
