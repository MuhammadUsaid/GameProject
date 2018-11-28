#include "Game.h"
using namespace std;

int main(int argc, char* argv[])
{
    /** Stuff To Limit Frame Rate **/
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    Game game; //Creating a Game object
    while(game.isRunning())
    {
        frameStart = SDL_GetTicks();  //Calculate the milliseconds since the SDL starts
        game.HandleEvents();
        game.Update();
        cout << Screen::pause << '\t';
        game.Render();
        frameTime = SDL_GetTicks() - frameStart; //Calculate the difference between every instance
        /** Limiting Frame Rate To 60 FPS **/
        if(frameTime < frameDelay)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    return 0;
}
