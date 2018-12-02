#include "Inventory.h"
#include "Player.h"
#include "Game.h"
Inventory::Inventory()
{
    weapons = Player::GetInstance()->GetWeapons();
}
void Inventory::Render()
{
    for(int i = 0; i < 10; i++)
    {
        SDL_Rect dst = {(i * 30) + 600, 10, 25, 25};
        SDL_RenderCopy(Game::renderer, weapons[i]->GetTexture(), weapons[i]->GetSrc() , &dst);
        //weapons[i]->Render();
    }
}
Inventory::~Inventory()
{

}
