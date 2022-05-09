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

bool window::loadImage(std::string path, SDL_Renderer* screen)
{
    free();
     SDL_Texture* newTexture = NULL;
     SDL_Surface* loadSurface = IMG_Load(path.c_str());
     SDL_SetColorKey(loadSurface, SDL_TRUE, SDL_MapRGB(loadSurface->format, 0xFF, 0, 0xFF));
     newTexture = SDL_CreateTextureFromSurface(screen, loadSurface);
     width = loadSurface->w;
     height = loadSurface->h;
     SDL_FreeSurface(loadSurface);
     object_ = newTexture;
     return (object_ != NULL);
}

void window::render(SDL_Renderer* des, SDL_Rect* clip)
{
    SDL_Rect renderquad = {rect_.x, rect_.y, rect_.w, rect_.h};
    SDL_RenderCopy(des, object_, clip, &renderquad);
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

