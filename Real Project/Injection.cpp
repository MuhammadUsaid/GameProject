#include "Injection.h"

Injection::Injection()
{

}

Injection::Injection(const char* path, int x, int y, int width, int height, int power, int range): Weapon(path, x, y, width, height, power, range)
{
    srcRect = {20, 550, 300, 290};
    type = INJECTION;
}
