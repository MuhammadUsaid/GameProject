#include "Chair.h"
#include "TextManager.h"

Chair::Chair()
{

}

Chair::Chair(const char* path, int x, int y, int width, int height):GameObject(path, x, y, width, height)
{
    srcRect = {450, 290, 150, 150};
}

void Chair::Render()
{
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
}
