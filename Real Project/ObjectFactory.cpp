#include "ObjectFactory.h"
#include "Bed.h"
#include "Chair.h"
#include "Cupboard.h"
#include "Table.h"
#include "Apple.h"
#include "Door.h"
#include "BananaPeel.h"
#include "Injection.h"
#include "Scalpel.h"

ObjectFactory::ObjectFactory()
{
    object = nullptr;
}
GameObject* ObjectFactory::getObject(int type, const char* path, int x, int y, int width, int height, int power, int range)
{
    switch(type)
    {
    case BED:
        object = new Bed(path, x, y, width, height);
        break;
    case CHAIR:
        object = new Chair(path, x, y, width, height);
        break;
    case CUPBOARD:
        object = new Cupboard(path, x, y, width, height);
        break;
    case WALL:
        object = new GameObject(path, x, y, width, height);
        break;
    case TABLE:
        object = new Table(path, x, y, width, height);
        break;
    case APPLE:
        object = new Apple(path, x, y, width, height, power, range);
        break;
    case INJECTION:
        object = new Injection(path, x, y, width, height, power, range);
        break;
    case SCALPEL:
        object = new Scalpel(path, x, y, width, height, power, range);
        break;
    case BANANAPEEL:
        object = new BananaPeel(path, x, y, width, height);
        break;
    case DOOR:
        object = new Door(path, x, y, width, height);
        break;
    }
    return object;
}
ObjectFactory::~ObjectFactory()
{

}
