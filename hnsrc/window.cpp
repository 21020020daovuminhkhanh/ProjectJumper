#include "window.h"


window::window()
{
    object_ = NULL;
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = SCREEN_WIDTH;
    rect_.h = SCREEN_HEIGHT;
}

window::~window()
{
    free();
}

bool window::loadImage(string path, SDL_Renderer* screen)
{
    free();
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadSurface = IMG_Load(path.c_str());
    SDL_SetColorKey(loadSurface, SDL_TRUE, SDL_MapRGB(loadSurface->format, 167, 175, 180));
    newTexture = SDL_CreateTextureFromSurface(screen, loadSurface);
    rect_.w = loadSurface -> w;
    rect_.h = loadSurface -> h;
    SDL_FreeSurface(loadSurface);
    object_ = newTexture;
    return (object_ != NULL);
}

void window::render(SDL_Renderer* renderer, SDL_Rect* clip)
{
    SDL_RenderCopy(renderer, object_, clip, &rect_);
}

void window::free()
{
    SDL_DestroyTexture(object_);
    object_ = NULL;
    rect_.w = SCREEN_WIDTH;
    rect_.h = SCREEN_HEIGHT;
}

void window::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	SDL_SetTextureColorMod( object_, red, green, blue );
}

void window::setAlpha(Uint8 alpha)
{
    SDL_SetTextureAlphaMod(object_, alpha);
}

void window::renderWithRotation(SDL_Renderer* renderer, SDL_Rect* clip, int rotation)
{
    SDL_RenderCopyEx(renderer, object_, clip, &rect_, rotation, NULL, SDL_FLIP_NONE);
}
