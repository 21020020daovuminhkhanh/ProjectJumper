#include "gameMenu.h"

LButton::LButton()
{
	mPosition.x = 0;
	mPosition.y = 0;
	mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

void LButton::setPosition( int x, int y )
{
	mPosition.x = x;
	mPosition.y = y;
}

void LButton::handleEvent( SDL_Event* e, bool &quit , int status, int &page)
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
				if (status == 0) page = 1;
				if (status == 1) quit = true;
				if (status == 2) page = 0;
				if (status == 3) page = 2;
				if (status == 4) quit = true;
				break;
			}
		}
	}
}

void LButton::setClip()
{
    for (int i = 0; i < BUTTON_SPRITE_TOTAL; i++)
    {
        gSpriteClips[i].x = 0;
        gSpriteClips[i].y = 91 * i;
        gSpriteClips[i].w = 540;
        gSpriteClips[i].h = 91;
    }
}

void LButton::renderButton(SDL_Renderer* renderer)
{
    setClip();
	button.render( renderer, &gSpriteClips[ mCurrentSprite ] );
}





startMenu::startMenu()
{

}

bool startMenu::loadMenu(SDL_Renderer* renderer)
{
    bool flag1 = backgroundMenu.loadImage("image/menuGame.png", renderer);
    bool flag2 = playButton.button.loadImage("image/playButton.png", renderer);
    bool flag3 = quitButton.button.loadImage("image/quitButton.png", renderer);
    if (flag1 == false || flag2 == false || flag3 == false) return false;
    else return true;
}

void startMenu::handleEvent( SDL_Event* e, bool& quit, int &page)
{
	playButton.handleEvent(e, quit, 0, page);
	quitButton.handleEvent(e, quit, 1, page);

}

void startMenu::renderMenu(SDL_Renderer* renderer)
{
    backgroundMenu.render(renderer, NULL);
    playButton.button.setRect(377, 200, 270, 45);
    playButton.setPosition(377, 200);
    playButton.renderButton(renderer);
    quitButton.button.setRect(377, 245, 270, 45);
    quitButton.setPosition(377, 245);
    quitButton.renderButton(renderer);
}




midMenu::midMenu()
{

}

bool midMenu::loadMenu(SDL_Renderer* renderer)
{
    bool flag1 = backgroundMenu.loadImage("image/chooseLevel.png", renderer);
    bool flag2 = levelButton[0].button.loadImage("image/level1Button.png", renderer);
    bool flag4 = levelButton[1].button.loadImage("image/level2Button.png", renderer);
    bool flag3 = backButton.button.loadImage("image/backButton.png", renderer);
    if (flag1 == false || flag2 == false || flag3 == false || flag4 == false) return false;
    else return true;
}

void midMenu::handleEvent(SDL_Event* e, bool &quit, int &page)
{
    levelButton[0].handleEvent(e, quit, 3, page);
    levelButton[1].handleEvent(e, quit, 4, page);
    backButton.handleEvent(e, quit, 2, page);
}

void midMenu::renderMenu(SDL_Renderer* renderer)
{
    backgroundMenu.render(renderer, NULL);
    levelButton[0].button.setRect(377, 200, 270, 45);
    levelButton[0].setPosition(377, 200);
    levelButton[0].renderButton(renderer);
    levelButton[1].button.setRect(377, 245, 270, 45);
    levelButton[1].setPosition(377, 245);
    levelButton[1].renderButton(renderer);
    backButton.button.setRect(377, 400, 270, 45);
    backButton.setPosition(377, 400);
    backButton.renderButton(renderer);
}
