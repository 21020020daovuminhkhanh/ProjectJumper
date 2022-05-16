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



    SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8 *wavBuffer;
	SDL_AudioDeviceID deviceId;
    player gPlayer;
    gamemap gMap;
    window gBackground;
    window gGround;
    window gLine;
    window object;
    bool flag;
    SDL_Rect bg;
    SDL_Rect gr;
    SDL_Rect* clip;
    int MAP_X = 1000;
};


#endif // RENDER_H_INCLUDED
