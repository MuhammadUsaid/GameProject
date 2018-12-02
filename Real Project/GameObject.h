#pragma once
#include <SDL2/SDL.h>
enum TYPE{WALL, BED, CUPBOARD, CHAIR, TABLE, APPLE, INJECTION, SCALPEL, BANANAPEEL, DOOR};
class GameObject
{
protected:
    int x;
    int y;
    int width;
    int height;
    int type;
    bool exists;
    SDL_Texture* texture;
    SDL_Rect dstRect;
    SDL_Rect srcRect;
public:
    bool isInPlayer;
    GameObject();
    GameObject(const char* path, int x, int y, int width, int height);
    int GetX();
    int GetY();
    int GetWidth();
    int GetHeight();
    bool GetExistence();
    int GetType();
    virtual bool GetKeyState();
    virtual SDL_Texture* GetTexture();
    virtual SDL_Rect* GetSrc();
    SDL_Rect GetRect();
    void SetX(int);
    void SetY(int);
    void SetExistence(bool);
    virtual void SetKeyState(bool);
    bool PointInRect(int,int,SDL_Rect);
    bool CheckCollision(SDL_Rect,SDL_Rect);
    virtual void Update();
    virtual void Render();
    virtual ~GameObject();
};
