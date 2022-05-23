#ifndef GAMEMENU_H_INCLUDED
#define GAMEMENU_H_INCLUDED

#include "window.h"
#include "utility.h"
#include "render.h"

const int NUMBER_OF_LEVEL = 2;
class LButton
{
public:
    LButton();
    void setPosition( int x, int y );
    void handleEvent( SDL_Event* e, bool &quit, int buttonType, int &page );
    void setClip();
    void renderButton(SDL_Renderer* renderer);


    SDL_Point mPosition;
    LButtonSprite mCurrentSprite;
    window button;
    SDL_Rect gSpriteClips[BUTTON_SPRITE_TOTAL];
};


class startMenu
{
public:
    startMenu();
    void renderMenu(SDL_Renderer* renderer);
    void handleEvent(SDL_Event *e, bool &quit, int &page);
    bool loadMenu(SDL_Renderer* renderer);

private:
    window backgroundMenu;
    LButton playButton;
    LButton quitButton;
};


class midMenu
{
public:
    midMenu();
    void renderMenu(SDL_Renderer* renderer);
    void handleEvent(SDL_Event *e, bool &quit, int& page);
    bool loadMenu(SDL_Renderer* renderer);

private:
    window backgroundMenu;
    LButton levelButton[NUMBER_OF_LEVEL];
    LButton backButton;
};


class winMenu
{
public:
    winMenu();
    void renderMenu(SDL_Renderer* renderer);
    void handleEvent(SDL_Event *e, bool &quit, int& page, int level);
    bool loadMenu(SDL_Renderer* renderer);

private:
    window backgroundMenu;
    LButton replayButton;
    LButton backButton;
};


class pauseMenu
{
public:
    pauseMenu();
    void renderMenu(SDL_Renderer* renderer);
    void handleEvent(SDL_Event *e, bool &quit, int& page, int level);
    bool loadMenu(SDL_Renderer* renderer);

private:
    window backgroundMenu;
    LButton replayButton;
    LButton resumeButton;
    LButton backButton;
};
#endif // GAMEMENU_H_INCLUDED
