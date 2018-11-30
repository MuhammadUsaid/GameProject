#include "Inventory.h"
#include "Player.h"

Inventory::Inventory()
{
    weapons = Player::GetInstance()->GetWeapons();
}
void Inventory::Render()
{
    for(int i = 0; i < 10; i++)
    {
        weapons[i].Render();
    }
}
Inventory::~Inventory()
{

}
