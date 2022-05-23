#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#pragma once
#include "window.h"

class player {
public:
	player();
	void update(SDL_Renderer* renderer, int input, int &mode);
	bool collisions(SDL_Rect objectRect, int objectType, int &mode);

	window gPlayer;
	float rotation = 0;
	float jumpVel = 0;
	float flyingVel = 0;
	int mode = 0;
};


#endif // PLAYER_H_INCLUDED
