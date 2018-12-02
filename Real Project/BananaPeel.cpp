#include "BananaPeel.h"

BananaPeel::BananaPeel(){}

BananaPeel::BananaPeel(const char* path, int x, int y, int width, int height):GameObject(path, x, y, width, height)
{
    srcRect = {390, 0, 270, 170};
    type = BANANAPEEL;
}
