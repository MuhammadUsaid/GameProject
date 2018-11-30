#include "Scissor.h"

Scissor::Scissor(){}

Scissor::Scissor(const char* path, int x, int y, int width, int height, int power, int range): Weapon(path, x, y, width, height, power, range)
{
    srcRect = {850, 70, 70, 165};
}
