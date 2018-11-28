#pragma once
#include "Character.h"

class Word
{
private:
    int x, y;
    std::string text; //text of the word
    int wordLen;  //length of the word
    int width;   //width of the word
    int height; //height of the word
    SDL_Texture* spriteSheetTexture;
    Character* chars; //pointer of character class(used for creating dynamic array of Characters)

public:
    Word();
    Word(std::string, SDL_Texture*, float, float );
    ~Word();
    void Render(); //to draw the word on screen
    int getLength();
    int getWidth();
    void changeWord(std::string);  //changes the text of the Word
    void operator = (const Word&); //operating overloading for assignment operator.
    std::string getText() {return text;} //used to get text of the word
};
