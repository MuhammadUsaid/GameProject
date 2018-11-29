#include "Player.h"
#include "TextManager.h"

Player* Player::instance = nullptr;

Player::Player()
{
    texture = TextureManager::LoadTexture("Images/boy.png");
    x = 512;
    y = 730;
    alive = true;
    health = 20;
    speed = 10;
    width = 40;
    height = 40;
    srcRect = {150, 0, 50, 50};
    SetClips();
}

Player* Player::GetInstance()
{
    if(instance == nullptr)
    {
        instance =  new Player;
    }
    return instance;
}
void Player::SetClips()
{
    for(int i = 0; i < 4; i++)
    {
        moveUp[i] = {i * 50, 200, 50, 50};
        moveDown[i] = {i * 50, 150, 50, 50};
        moveRight[i] = {i * 50, 50, 50, 50};
        moveLeft[i] = {i * 50, 100, 50, 50};
    }
}
bool Player::CompareRects(SDL_Rect a, SDL_Rect b)
{
    if (a.w == b.w && a.h == b.h && a.x == b.x && a.y == b.y)
    {
        return true;
    }
    return false;
}

void Player::MoveUp()
{
    if (y > 0)
        y -= speed;
    for(int i = 0; i < 3; i++)
    {
        if ( CompareRects(moveUp[i], srcRect) )
        {
            srcRect = moveUp[i+1];
            return;
        }
    }
    srcRect = moveUp[0];
}

void Player::MoveDown()
{
    if (y < 768 - height)
        y += speed;
    for(int i = 0; i < 3; i++)
    {
        if ( CompareRects(moveDown[i], srcRect) )
        {
            srcRect = moveDown[i+1];
            return;
        }
    }
    srcRect = moveDown[0];
}
void Player::MoveRight()
{
    if(x < 1024 - width)
    {
        x += speed;
    }
    for(int i = 0; i < 3; i++)
    {
        if ( CompareRects(moveRight[i], srcRect) )
        {
            srcRect = moveRight[i+1];
            return;
        }
    }
    srcRect = moveRight[0];
}
void Player::MoveLeft()
{
    if(x > 0)
    {
        x -= speed;
    }
    for(int i = 0; i < 3; i++)
    {
        if ( CompareRects(moveLeft[i], srcRect) )
        {
            srcRect = moveLeft[i+1];
            return;
        }
    }
    srcRect = moveLeft[0];
}
void Player::Update()
{
    dstRect = {x, y, width, height};
}
void Player::Render()
{
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
}
Player::~Player()
{
    delete instance;
    instance = nullptr;
}
