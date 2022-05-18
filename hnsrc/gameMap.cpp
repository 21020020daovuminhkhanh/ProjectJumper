#include "gameMap.h"


void gamemap::setObject(int level)
{
    setClips();
    int objectType, objectX, objectY, objectW, objectH, objectAngle;
    switch (level)
    {
        case 1:
            {
            ifstream openFile("file/level1.dat");
            while(openFile >> objectType >> objectX >> objectY >> objectW >> objectH >> objectAngle)
            {
                od.emplace_back(objectType, objectX, objectY, objectW, objectH, objectAngle);
            }
            break;
            }
        case 2:
            {
            ifstream openFile("file/level2.dat");
            while(openFile >> objectType >> objectX >> objectY >> objectW >> objectH >> objectAngle)
            {
                od.emplace_back(objectType, objectX, objectY, objectW, objectH, objectAngle);
            }
            break;
            }
        case 3:
            {
            ifstream openFile("file/level3.dat");
            while(openFile >> objectType >> objectX >> objectY >> objectW >> objectH >> objectAngle)
            {
            od.emplace_back(objectType, objectX, objectY, objectW, objectH, objectAngle);
            }
            break;
            }
    }
}


void gamemap::setClips()
{
    for (int i = 0; i < NUMBER_OF_OBJECT; i++)
    {
        if (i <= BLOCK)
        {
            clips[i].x = 44*i;
            clips[i].y = 0;
            clips[i].w = 42;
            clips[i].h = 42;
        }
        else if (SPIKE <= i && i <= SPIKE_GRASS)
        {
            clips[i].x = 44 * (i - 2);
            clips[i].y = 0;
            clips[i].w = 42;
            clips[i].h = 42;
        }
        else if (FOUR_SIDES_WINDOW <= i && i <= NO_SIDE_BLOCK)
        {
            clips[i].x = 44 * (i - 6);
            clips[i].y = 0;
            clips[i].w = 42;
            clips[i].h = 42;
        }
        else if (THREE_SIDES_WINDOW <= i && i <= TWO_SIDES_BLOCK)
        {
            clips[i].x = 44 * (i - 12);
            clips[i].y = 44;
            clips[i].w = 42;
            clips[i].h = 42;
        }
        else
        {
            clips[i].x = 46 * (i - 18);
            clips[i].y = 0;
            clips[i].w = 44;
            clips[i].h = 85;
        }
    }
}

