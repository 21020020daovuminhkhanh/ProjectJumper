#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#pragma once
#include "utility.h"

class window
{
public:
    window();
    ~window();

    void setRect(const int &x, const int &y, const int &w, const int &h)
    {
        rect_ = {x, y, w, h};
    }

    SDL_Rect getRect()
    {
        return rect_;
    }

    SDL_Texture* getTexture()
    {
        return object_;
    }

    bool loadImage(string path, SDL_Renderer* screen);
    void render(SDL_Renderer* renderer, SDL_Rect* clip = NULL);
    void renderWithRotation(SDL_Renderer* renderer, SDL_Rect* clip, int rotation);
    void setColor( Uint8 red, Uint8 green, Uint8 blue );
    void setAlpha(Uint8 alpha);
    void free();


public:
    SDL_Texture* object_;
    SDL_Rect rect_;
};


#endif // WINDOW_H_INCLUDED
