#include "Health.h"
#include"Game.h"
#include "Player.h"

Health::Health()
{
    int x = 10;
    int y = 10;
    health = Player::GetInstance()->GetHealth();
    barLength = health;
    fullBar = {x, y, 100, 10};
    healthBar = {x, y, barLength, 10};
}

void Health::Update()
{
    health = Player::GetInstance()->GetHealth();
    barLength = health;
    healthBar.w = barLength;
}

void Health::Render()
{
    SDL_SetRenderDrawColor(Game::renderer,  0x00, 0xFF, 0x00, 0xFF); //green color
    if (health <= 20)
        SDL_SetRenderDrawColor(Game::renderer,  0xFF, 0x00, 0x00, 0xFF); //red color
    SDL_RenderDrawRect(Game::renderer, &fullBar);
    SDL_RenderFillRect(Game::renderer, &healthBar);
}
