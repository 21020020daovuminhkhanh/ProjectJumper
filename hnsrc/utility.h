#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 576;

static SDL_Window* gWindow = NULL;
static SDL_Renderer* gScreen = NULL;
static SDL_Event gEvent;

const int LIGHT_BLUE_R = 0;
const int LIGHT_BLUE_G = 0;
const int LIGHT_BLUE_B = 255;

enum objectType
{
    SMALL_BLOCK,
    BLOCK,
    SPIKE,
    SHORT_SPIKE,
    SMALL_SPIKE,
    SPIKE_GRASS,
    FOUR_SIDES_WINDOW,
    FOUR_SIDES_BLOCK,
    ONE_SIDE_WINDOW,
    ONE_SIDE_BLOCK,
    NO_SIDE_WINDOW,
    NO_SIDE_BLOCK,
    THREE_SIDES_WINDOW,
    THREE_SIDES_BLOCK,
    TWO_SIDES_P_WINDOW,
    TWO_SIDES_P_BLOCK,
    TWO_SIDES_WINDOW,
    TWO_SIDES_BLOCK,
    NUMBER_OF_OBJECT,
};



#endif // UTILITY_H_INCLUDED
