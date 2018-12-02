#include "Apple.h"

Apple::Apple(){}

Apple::Apple(const char* path, int x, int y, int width, int height, int power, int range):Weapon(path, x, y, width, height, power, range)
{
    srcRect =  {750, 370, 100, 90};
    type = APPLE;
}
//void Apple::Render()
//{
//    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
//}
Apple::~Apple()
{

}
