#include "Door.h"
#include "TextManager.h"
#include <iostream>
using namespace std;

Door::Door()
{
}

Door::Door(const char* path, int x, int y, int width, int height):GameObject(path, x, y, width, height)
{
    srcRect = {0, 100, 64, 80};
    type =  DOOR;
}

void Door::Render()
{
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
}

