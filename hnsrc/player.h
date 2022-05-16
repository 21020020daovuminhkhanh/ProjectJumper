#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#pragma once
#include "window.h"

class player {
public:
	player(SDL_Renderer* ren);
	player();
	void update(SDL_Renderer* renderer, int input, int status);
	bool collisions(SDL_Rect objectRect, int objectType);

	window gPlayer;
	//window cube;
	//window ship;
	float rotation = 0;
	float acc = 0;
	int status = 0;
};


#endif // PLAYER_H_INCLUDED
