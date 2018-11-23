#include "Button.h"
#include "Game.h"
//#include<vector>
//#include<sstream>

using namespace std;

Button::Button()
{
    width=0;
    height=0;
    ButtonWidth=0;
    state=0;
    word = NULL;
}

Button::Button(SDL_Texture* image,string text, float x, float y)
{
    state = Normal;                                               ///initial state of button is always Normal
    this->x = x;
    this->y = y;

    spriteSheetTexture=image;
    this->text=text;

    spriteClips[Normal].x = 0;
    spriteClips[Normal].y = 256;
    spriteClips[Normal].w = 32;
    spriteClips[Normal].h = 60;
    spriteClips[Hover].x = 0;
    spriteClips[Hover].y = 326;
    spriteClips[Hover].w = 32;
    spriteClips[Hover].h = 60;
    spriteClips[Clicked].x = 0;
    spriteClips[Clicked].y = 396;
    spriteClips[Clicked].w = 32;
    spriteClips[Clicked].h = 60;

    this->width = spriteClips[0].w;
    this->height = spriteClips[0].h;
    int textLength= text.size();             ///size of the text
    if(textLength%2==0)                     ///Button Width is decided on whether text size is even or odd
        textLength=textLength-1;
    ButtonWidth=width*(textLength+2);
    word = new Word(text,spriteSheetTexture,x,y-10);
}

void Button::Render()
{
    int textLength = word->getLength();
    float posX=x-(32*((textLength-1)/2)+16)-16; ///Position for the left part of the button
    spriteClips[state].x = 0;  ///selects the spriteClip according to Button State
    SDL_Rect dst = {posX - width/2, y - height/2, width, height};
    SDL_RenderCopy(Game::renderer, spriteSheetTexture, &spriteClips[state], &dst);
    spriteClips[state].x=48;        ///Middle part of the Button
    int limit;                      ///limit of the for loop (below) decided according to text size
    if(textLength%2==0)
    {
        limit=textLength-1;
    }
    else
    {
        limit=textLength;
    }

    ///rendering middle part of the button as a background for each character in the Word
    for(int i=0; i<limit; i++)
    {
        posX+=32;
        dst = {posX - width/2, y - height/2, width, height};
        SDL_RenderCopy(Game::renderer, spriteSheetTexture, &spriteClips[state], &dst);
    }

    spriteClips[state].x=112;       ///Right part of the Button
    posX = x+(32*((textLength-1)/2)+16)+16;          ///position for the right most part of the button
    dst = {posX - width/2, y - height/2, width, height};
    SDL_RenderCopy(Game::renderer, spriteSheetTexture, &spriteClips[state], &dst);
    //word=w;
    word->Render();
}

int Button::GetX()
{
    return x;
}

int Button::GetY()
{
    return y;
}

int Button::getWidth()
{
    return ButtonWidth;
}

int Button::getHeight()
{
    return height;
}

string Button::getText()
{
    return text;
}

void Button::changeState(State val)
{
    state=val;
}
bool Button::clicked()
{
    return (state == Clicked);
}
Button::~Button()
{
    cout <<"Button " << text << " is destroyed" << endl;
    if (word != NULL)
    {
        delete word;
        word = NULL;
    }
}

void Button::operator = (const Button& cpy)
{
    state=cpy.state;
    this->x=cpy.x;
    this->y=cpy.y;
    spriteSheetTexture=cpy.spriteSheetTexture;
    text=cpy.text;
    spriteClips[Normal]=cpy.spriteClips[Normal];
    spriteClips[Hover]=cpy.spriteClips[Hover];
    spriteClips[Clicked]=cpy.spriteClips[Clicked];
    width=cpy.width;
    height=cpy.height;
    ButtonWidth = cpy.ButtonWidth;
    this->word = new Word(text,spriteSheetTexture,x,y+8);
}

