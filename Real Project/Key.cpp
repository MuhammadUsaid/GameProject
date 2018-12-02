#include "Key.h"

Key::Key()
{

}
Key::Key(const char* path, int x, int y, int width, int height) : GameObject(path, x, y, width, height)
{
    srcRect = {0, 0, 260, 260};
}
