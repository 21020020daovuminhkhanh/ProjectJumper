#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#pragma once
#include "SDL.h"
#include "window.h"
#include "gamemap.h"
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
    bool loadScene(SDL_Renderer* renderer);
    void drawScene(SDL_Renderer* renderer, int input, bool &quit);



    Mix_Music *gMusic;
    Mix_Chunk *gDeadSound;
    player gPlayer;
    gamemap gMap;
    window gBackground;
    window gGround;
    window gLine;
    window object;
    window deadEffect;
    bool flag;
    SDL_Rect bg;
    SDL_Rect gr;
    SDL_Rect* clip;
    int MAP_X = 1000;
    int status = 0;
};


#endif // RENDER_H_INCLUDED
