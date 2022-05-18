#include "gameMenu.h"

gameMenu::gameMenu()
{
	mPosition.x = 0;
	mPosition.y = 0;
	mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

void gameMenu::setPosition( int x, int y )
{
	mPosition.x = x;
	mPosition.y = y;
}

void gameMenu::handleEvent( SDL_Event* e )
{
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		int x, y;
		SDL_GetMouseState( &x, &y );
		bool inside = true;

		if( x < mPosition.x )
		{
			inside = false;
		}
		else if( x > mPosition.x + BUTTON_WIDTH )
		{
			inside = false;
		}
		else if( y < mPosition.y )
		{
			inside = false;
		}
		else if( y > mPosition.y + BUTTON_HEIGHT )
		{
			inside = false;
		}

		if( !inside )
		{
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		else
		{
			switch( e->type )
			{
				case SDL_MOUSEMOTION:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;

				case SDL_MOUSEBUTTONDOWN:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
				break;

				case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
				break;
			}
		}
	}
}

void gameMenu::render(SDL_Renderer* renderer)
{
    setClip();
    bool flag;
    flag = menu.loadImage("image/menuGame.png", renderer);
    menu.render(renderer, NULL);
	flag = playButton.loadImage("image/playButton.png", renderer);
	playButton.setRect(242, 200, 540, 91);
	playButton.render(renderer, &gSpriteClips[mCurrentSprite]);
	flag = quitButton.loadImage("image/quitButton.png", renderer);
	quitButton.setRect(242, 291, 540, 91);
	quitButton.render(renderer, &gSpriteClips[mCurrentSprite]);
}

void gameMenu::setClip()
{
    for (int i = 0; i < BUTTON_SPRITE_TOTAL; i++)
    {
        gSpriteClips[i].x = 0;
        gSpriteClips[i].y = 91 * i;
        gSpriteClips[i].w = 540;
        gSpriteClips[i].h = 91;
    }
}
