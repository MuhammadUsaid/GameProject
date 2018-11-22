#pragma once
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

class Game
{
public:
    /** Constructor **/
    Game();
    /** Attributes **/
    static SDL_Renderer* renderer;
//    Screen* currentScreen = nullptr;
    static int width;
    static int height;
    /** Methods **/
    void HandleEvents();
    void Update();
    void Render();
    bool isRunning();
    /** Destructor **/
    ~Game();
private:
    bool running;
    SDL_Window* window;
    void Init();
    //void ShowSplash(); //To show splash screen for 3 seconds
};

