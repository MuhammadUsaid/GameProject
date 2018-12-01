#include "Table.h"
#include "Game.h"
Table::Table(){}

Table::Table(const char* path, int x, int y, int width, int height): GameObject(path, x, y, width, height)
{
    srcRect = {10, 340, 300, 180};
}
void Table::Render()
{
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
}
