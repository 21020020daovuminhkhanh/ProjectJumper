#ifndef GAMEMAP_H_INCLUDED
#define GAMEMAP_H_INCLUDED

#include <fstream>
#include "utility.h"
#include "window.h"
#include <vector>

struct objectData
{
    int objectType;
    int objectX;
    int objectY;
    int objectW;
    int objectH;
    int objectAngle;
    SDL_Rect objectRect;

    objectData(int t, int x, int y, int w, int h, int angle)
    {
        objectType = t;
        objectX = x;
        objectY = y;
        objectW = w;
        objectH = h;
        objectAngle = angle;
        objectRect = {x, y, w, h};
    }
};

class gamemap
{
public:
    gamemap(){}
    ~gamemap(){}

    void setClips();
    void setObject(int level);

public:
    SDL_Rect clips[NUMBER_OF_OBJECT];
    SDL_Rect* clip_;
    vector<objectData> od;
};

#endif // GAMEMAP_H_INCLUDED
