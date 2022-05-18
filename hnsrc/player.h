#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#pragma once
#include "window.h"

class player {
public:
	player();
	void update(SDL_Renderer* renderer, int input, int status);
	bool collisions(SDL_Rect objectRect, int objectType, int &status);

	window gPlayer;
	float rotation = 0;
	float jumpVel = 0;
	float flyingVel = 0;
	int status = 0;
};


#endif // PLAYER_H_INCLUDED
