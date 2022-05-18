#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include "SDL_ttf.h"
#include "SDL_mixer.h"

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
    PINK_PORTAL,
    GREEN_PORTAL,
    NUMBER_OF_OBJECT,
};

const int BUTTON_WIDTH = 540;
const int BUTTON_HEIGHT = 91;
const int TOTAL_BUTTONS = 3;

enum LButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_TOTAL = 3
};

#endif // UTILITY_H_INCLUDED
