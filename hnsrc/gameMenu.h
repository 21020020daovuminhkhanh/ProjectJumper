#ifndef GAMEMENU_H_INCLUDED
#define GAMEMENU_H_INCLUDED

#include "window.h"
#include "utility.h"

class LButton
{
public:
    LButton();
    void setPosition( int x, int y );
    void handleEvent( SDL_Event* e, bool &quit, int status, int &page );
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
    LButton levelButton[2];
    LButton backButton;
};
#endif // GAMEMENU_H_INCLUDED
