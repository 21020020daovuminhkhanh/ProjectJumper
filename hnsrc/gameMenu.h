#ifndef GAMEMENU_H_INCLUDED
#define GAMEMENU_H_INCLUDED

#include "window.h"
#include "utility.h"

class gameMenu
{
public:
    gameMenu();
    //void setMenu(SDL_Renderer* renderer);
    void setPosition( int x, int y );
    void handleEvent( SDL_Event* e );
    void setClip();
    void render(SDL_Renderer* renderer);

private:
    window menu;
    window playButton;
    window quitButton;
    SDL_Point mPosition;
    LButtonSprite mCurrentSprite;
    SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ];
};

#endif // GAMEMENU_H_INCLUDED
