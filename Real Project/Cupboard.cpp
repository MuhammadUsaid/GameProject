#include "Cupboard.h"
#include "TextManager.h"

Cupboard::Cupboard()
{

}

Cupboard::Cupboard(const char* path, int x, int y, int width, int height):GameObject(path, x, y, width, height)
{
    srcRect = {725, 520, 240, 330};
    type = CUPBOARD;
    containsKey = false;
}

void Cupboard::Render()
{
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
}

bool Cupboard::GetKeyState()
{
    return containsKey;
}

void Cupboard::SetKeyState(bool input)
{
    containsKey = input;
}
