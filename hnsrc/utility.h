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

const int BUTTON_WIDTH = 270;
const int BUTTON_HEIGHT = 45;
const int TOTAL_BUTTONS = 3;

enum LButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_TOTAL = 3
};

enum mode
{
    CUBE = 0,
    SHIP = 1,
};

enum buttonType
{
    PLAY = 0,
    QUIT = 1,
    BACK = 2,
    LEVEL1 = 3,
    LEVEL2 = 4,
    RESUME1 = 5,
    RESUME2 = 6,
    REPLAY1 = 5,
    REPLAY2 = 6,
};

enum page
{
    START_MENU = 0,
    MID_MENU = 1,
    LEVEL1_PAGE = 2,
    LEVEL2_PAGE = 3,
    WIN_MENU = 4,
    PAUSE_MENU = 5,
};


#endif // UTILITY_H_INCLUDED
