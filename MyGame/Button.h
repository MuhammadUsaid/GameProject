#pragma once
#include "Word.h"

enum State{Normal, Hover, Clicked};                                 ///Enumerating three states of buttons

class Button
{
    int width;  //width of each of the three parts of the button
    int ButtonWidth; //final width of the Button
    int height; //height of the Button
    std::string text;//Text on the button
    Word* word; //object of word class to be rendered over the button
    SDL_Rect spriteClips[3]; //sprite clips for each state of the button
    SDL_Texture* spriteSheetTexture; //Texture of image consisting of Buttons
    int x , y;
    int state; //current state of the Button

public:
    Button();
    Button(SDL_Texture*,std::string, float, float);
    void Render();
    ~Button();
    int GetX();
    int GetY();
    int GetWidth();
    int GetHeight();
    std::string GetText(); //get the text of the button
    void ChangeState(State); //changes the current state of the button
    void operator = (const Button& cpy); //operator overloading for assignment operator
    bool Clicked(); //tells whether button is clicked or not
};
