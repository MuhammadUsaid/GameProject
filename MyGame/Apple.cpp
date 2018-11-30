#include "Apple.h"

Apple::Apple(){}

Apple::Apple(const char* path, int x, int y, int width, int height, int power, int range)
{
    srcRect =  {750, 370, 100, 90};
}
//void Apple::Render()
//{
//    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
//}
Apple::~Apple()
{

}
