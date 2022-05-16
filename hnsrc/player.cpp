#include "player.h"
#include <math.h>
#include <iostream>

player::player(SDL_Renderer* renderer) {
	gPlayer.setRect(300, 390, 42, 42);
}
player::player() {gPlayer.setRect(300, 390, 42, 42);}

bool player::collisions(SDL_Rect objectRect, int objectType) {
    if (objectType <= 1 || (objectType >= 6 && objectType <= 17))
    {
        if((gPlayer.rect_.y >= objectRect.y - 42) &&
           (gPlayer.rect_.y <= objectRect.y) &&
           (gPlayer.rect_.x >= objectRect.x - 42) &&
           (gPlayer.rect_.x < objectRect.x + 42))
        {
            gPlayer.rect_.y = objectRect.y - 52;
            acc = 0;
        }
        else if ((gPlayer.rect_.y <= objectRect.y + 42) &&
                (gPlayer.rect_.y >= objectRect.y) &&
                (gPlayer.rect_.x >= objectRect.x - 42) &&
                 (gPlayer.rect_.x <= objectRect.x))
        {
            return false;
        }
    }
    if (objectType >= 2 && objectType <= 5)
    {
        if((gPlayer.rect_.y >= objectRect.y - 40) &&
           (gPlayer.rect_.y <= objectRect.y + 1) &&
           (gPlayer.rect_.x >= objectRect.x - 42) &&
           (gPlayer.rect_.x < objectRect.x + 42))
        {
            return false;
        }
    }
    return true;
}

void player::update(SDL_Renderer* renderer, int input, int status) {
    if (status == 0)
    {
        if(gPlayer.rect_.y >= 390)
        {
            gPlayer.rect_.y = 390; acc = 0;
        }
        if((input == 1) && (acc == 0))
        {
            acc = -28;
        }
        if (acc != 0) rotation += 8;
        if (acc == 0) rotation = round(rotation/90) * 90;
        if (rotation >= 360) rotation = 0;
        acc += 1.6;
        gPlayer.rect_.y += acc;
        gPlayer.renderWithRotation(renderer, NULL, rotation);
    }
    else
    {

    }
}
