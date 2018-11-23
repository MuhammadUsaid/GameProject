#pragma once
#include <SDL2/SDL_image.h>
#include "Game.h"

class TextureManager
{
    public:
        TextureManager()
        {}
        static SDL_Texture* LoadTexture(const char* path)
        {
            SDL_Surface* surface = IMG_Load(path);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
            SDL_FreeSurface(surface);
            return texture;
        }
};
