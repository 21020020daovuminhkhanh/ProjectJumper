#include "player.h"
#include <math.h>
#include <iostream>

player::player() {}

bool player::collisions(SDL_Rect objectRect, int objectType, int &status) {
    if (objectType <= BLOCK || (objectType >= FOUR_SIDES_WINDOW && objectType <= TWO_SIDES_BLOCK))
    {
        if((gPlayer.rect_.y >= objectRect.y - 42) &&
           (gPlayer.rect_.y <= objectRect.y) &&
           (gPlayer.rect_.x >= objectRect.x - 42) &&
           (gPlayer.rect_.x < objectRect.x + 42))
        {
            gPlayer.rect_.y = objectRect.y - 52;
            jumpVel = 0;
        }
        else if ((gPlayer.rect_.y <= objectRect.y + 42) &&
                (gPlayer.rect_.y >= objectRect.y) &&
                (gPlayer.rect_.x >= objectRect.x - 42) &&
                 (gPlayer.rect_.x <= objectRect.x))
        {
            return false;
        }
    }
    else if (objectType == SPIKE)
    {
        if((gPlayer.rect_.y >= objectRect.y - 40) &&
           (gPlayer.rect_.y <= objectRect.y + 1) &&
           (gPlayer.rect_.x >= objectRect.x - 30) &&
           (gPlayer.rect_.x < objectRect.x + 30))
        {
            return false;
        }
    }
    else if (objectType >= SHORT_SPIKE && objectType <= SPIKE_GRASS)
    {
        if((gPlayer.rect_.y >= objectRect.y - 10) &&
           (gPlayer.rect_.y <= objectRect.y + 1) &&
           (gPlayer.rect_.x >= objectRect.x - 30) &&
           (gPlayer.rect_.x < objectRect.x + 30))
        {
            return false;
        }
    }
    else if (objectType == PINK_PORTAL)
    {
        if((gPlayer.rect_.y >= objectRect.y - 40) &&
           (gPlayer.rect_.y <= objectRect.y + 45) &&
           (gPlayer.rect_.x >= objectRect.x - 44) &&
           (gPlayer.rect_.x < objectRect.x + 44))
        status = 1;
    }
    else
    {
        if((gPlayer.rect_.y >= objectRect.y - 40) &&
           (gPlayer.rect_.y <= objectRect.y + 45) &&
           (gPlayer.rect_.x >= objectRect.x - 44) &&
           (gPlayer.rect_.x < objectRect.x + 44))
        status = 0;
    }
    return true;
}

void player::update(SDL_Renderer* renderer, int input, int status) {
    if (status == 0)
    {
        bool flag = gPlayer.loadImage("image/player.png", renderer);
        gPlayer.rect_.w = 42;
        gPlayer.rect_.h = 42;
        if(gPlayer.rect_.y >= 390)
        {
            gPlayer.rect_.y = 390; jumpVel = 0;
        }
        if((input == 1) && (jumpVel == 0))
        {
            jumpVel = -28;
        }
        if (jumpVel != 0) rotation += 8;
        if (jumpVel == 0) rotation = round(rotation/90) * 90;
        if (rotation >= 360) rotation = 0;
        jumpVel += 1.6;
        gPlayer.rect_.y += jumpVel;
        gPlayer.renderWithRotation(renderer, NULL, rotation);
    }
    else
    {
        bool flag = gPlayer.loadImage("image/spaceship.png", renderer);
        gPlayer.rect_.w = 42;
        gPlayer.rect_.h = 42;
        if(gPlayer.rect_.y >= 390)
        {
            gPlayer.rect_.y = 390;
            flyingVel = 0;
            rotation = 0;
        }
        if (input == 1)
        {
            flyingVel = -14;
            rotation -= 1;
            if (rotation <= -45) rotation = -45;
        }
        if (input == 0)
        {
            rotation += 1;
            if (rotation >= 45) rotation = 45;
        }
        flyingVel += 0.5;
        gPlayer.rect_.y += flyingVel;
        gPlayer.renderWithRotation(renderer, NULL, rotation);
    }
}
