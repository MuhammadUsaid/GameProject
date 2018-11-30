#include "Table.h"

Table::Table(){}

Table::Table(const char* path, int x, int y, int width, int height): GameObject(path, x, y, width, height)
{
    srcRect = {10, 340, 300, 150};
}
