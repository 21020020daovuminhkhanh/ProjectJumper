#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#pragma once
#include "SDL.h"
#include "window.h"
#include "gameMap.h"
#include "utility.h"
#include "player.h"

class render
{
public:
    render();
    ~render();
    render(SDL_Renderer* renderer, int level);
    void setBackground(SDL_Renderer* renderer);
    void setGround(SDL_Renderer* renderer);
    void setLine(SDL_Renderer* renderer);
    void setPlayer(SDL_Renderer* renderer, int input);
    bool loadScene(SDL_Renderer* renderer, int level);
    void drawScene(SDL_Renderer* renderer, int input, bool &quit, int &page);



    Mix_Music *gMusic;
    Mix_Chunk *gDeadSound;
    player gPlayer;
    gamemap gMap;
    window deadEffect;
    window gText;
    window gBackground;
    window gGround;
    window gLine;
    window object;
    bool flag;
    SDL_Rect bg;
    SDL_Rect gr;
    SDL_Rect* clip;
    int MAP_X = 1000;
    int mode = CUBE;
};


#endif // RENDER_H_INCLUDED
