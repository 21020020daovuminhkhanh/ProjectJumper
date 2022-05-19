#include <iostream>
#include "render.h"
#include "gameMenu.h"

using namespace std;

int input = 0;
int level = 1;
render scene(gScreen, level);
startMenu startMenu;
midMenu midMenu;

bool init()
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) success = false;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    gWindow = SDL_CreateWindow("Jumper", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL) success = false;
    else
    {
        gScreen = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
        if (gScreen == NULL) success = false;
        else
        {
            SDL_SetRenderDrawColor(gScreen, LIGHT_BLUE_R, LIGHT_BLUE_G, LIGHT_BLUE_B, 255);
            int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					success = false;
				}
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					success = false;
				}
        }
    }
    return success;
}

bool load()
{
    if (scene.loadScene(gScreen) == false) return false;
    if (startMenu.loadMenu(gScreen) == false) return false;
    if (midMenu.loadMenu(gScreen) == false) return false;
    else return true;
}

void close()
{
    SDL_DestroyRenderer(gScreen);
    gScreen = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    if (!init()) return -1;
    if (!load()) return -2;

    bool quit = false;
    int page = 0;
    while (!quit)
    {
        if (page == 0)
        {
            while(SDL_PollEvent(&gEvent) != 0)
            {
                if (gEvent.type == SDL_QUIT) quit = true;
                startMenu.handleEvent(&gEvent, quit, page);
            }

            SDL_RenderClear(gScreen);
            startMenu.renderMenu(gScreen);
            SDL_RenderPresent(gScreen);
        }
        if (page == 1)
        {
            while(SDL_PollEvent(&gEvent) != 0)
            {
                if (gEvent.type == SDL_QUIT) quit = true;
                midMenu.handleEvent(&gEvent, quit, page);
            }

            SDL_RenderClear(gScreen);
            midMenu.renderMenu(gScreen);
            SDL_RenderPresent(gScreen);
        }
        if (page == 2)
        {
            while(SDL_PollEvent(&gEvent) != 0)
            {
                if (gEvent.type == SDL_QUIT) quit = true;
                if (gEvent.type == SDL_KEYDOWN)
                {
                    if (gEvent.key.keysym.sym == SDLK_SPACE)
                        input = 1;
                    if (gEvent.key.keysym.sym == SDLK_ESCAPE)
                        quit = true;
                }
                if (gEvent.type == SDL_KEYUP) input = 0;
            }
            SDL_RenderClear(gScreen);
            scene.drawScene(gScreen, input, quit);
            SDL_RenderPresent(gScreen);
        }
    }
    close();
    return 0;
}
