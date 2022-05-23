#include "gameMenu.h"

const int buttonX1 = 377;
const int buttonY1 = 200;
const int buttonW1 = 270;
const int buttonH1 = 45;

const int buttonX2 = 377;
const int buttonY2 = 245;
const int buttonW2 = 270;
const int buttonH2 = 45;

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

void LButton::handleEvent( SDL_Event* e, bool &quit , int buttonType, int &page)
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
				if (buttonType == PLAY) page = MID_MENU;
				if (buttonType == QUIT) quit = true;
				if (buttonType == BACK) page = START_MENU;
				if (buttonType == LEVEL1) page = LEVEL1_PAGE;
				if (buttonType == LEVEL2) page = LEVEL2_PAGE;
				if (buttonType == RESUME1)
                {
                    page = LEVEL1_PAGE;
                    Mix_ResumeMusic();
                }
                if (buttonType == RESUME2)
                {
                    page = LEVEL2_PAGE;
                    Mix_ResumeMusic();
                }
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
    bool flag1 = backgroundMenu.loadImage("image/Menu/menuGame.png", renderer);
    bool flag2 = playButton.button.loadImage("image/Buttons/playButton.png", renderer);
    bool flag3 = quitButton.button.loadImage("image/Buttons/quitButton.png", renderer);
    if (flag1 == false || flag2 == false || flag3 == false) return false;
    else return true;
}

void startMenu::handleEvent( SDL_Event* e, bool& quit, int &page)
{
	playButton.handleEvent(e, quit, PLAY, page);
	quitButton.handleEvent(e, quit, QUIT, page);

}

void startMenu::renderMenu(SDL_Renderer* renderer)
{
    backgroundMenu.render(renderer, NULL);
    playButton.button.setRect( buttonX1, buttonY1, buttonW1, buttonH1 );
    playButton.setPosition( buttonX1, buttonY1 );
    playButton.renderButton(renderer);
    quitButton.button.setRect( buttonX2, buttonY2, buttonW2, buttonH2 );
    quitButton.setPosition( buttonX2, buttonY2 );
    quitButton.renderButton(renderer);
}




midMenu::midMenu()
{

}

bool midMenu::loadMenu(SDL_Renderer* renderer)
{
    bool flag1 = backgroundMenu.loadImage("image/Menu/chooseLevel.png", renderer);
    bool flag2 = levelButton[0].button.loadImage("image/Buttons/level1Button.png", renderer);
    bool flag4 = levelButton[1].button.loadImage("image/Buttons/level2Button.png", renderer);
    bool flag3 = backButton.button.loadImage("image/Buttons/backButton.png", renderer);
    if (flag1 == false || flag2 == false || flag3 == false || flag4 == false) return false;
    else return true;
}

void midMenu::handleEvent(SDL_Event* e, bool &quit, int &page)
{
    levelButton[0].handleEvent(e, quit, LEVEL1, page);
    levelButton[1].handleEvent(e, quit, LEVEL2, page);
    backButton.handleEvent(e, quit, BACK, page);
}

void midMenu::renderMenu(SDL_Renderer* renderer)
{
    backgroundMenu.render(renderer, NULL);
    levelButton[0].button.setRect( buttonX1, buttonY1, buttonW1, buttonH1 );
    levelButton[0].setPosition( buttonX1, buttonY1 );
    levelButton[0].renderButton(renderer);
    levelButton[1].button.setRect( buttonX2, buttonY2, buttonW2, buttonH2 );
    levelButton[1].setPosition( buttonX2, buttonY2 );
    levelButton[1].renderButton(renderer);
    backButton.button.setRect(377, 400, 270, 45);
    backButton.setPosition(377, 400);
    backButton.renderButton(renderer);
}




winMenu::winMenu()
{

}

bool winMenu::loadMenu(SDL_Renderer* renderer)
{
    bool flag1 = backgroundMenu.loadImage("image/Menu/winMenu.png", renderer);
    bool flag2 = replayButton.button.loadImage("image/Buttons/replayButton.png", renderer);
    bool flag3 = backButton.button.loadImage("image/Buttons/backButton.png", renderer);
    if (flag1 == false || flag2 == false || flag3 == false) return false;
    else return true;
}

void winMenu::handleEvent( SDL_Event* e, bool& quit, int &page, int level)
{
    if (level == 1) replayButton.handleEvent(e, quit, REPLAY1, page);
	else replayButton.handleEvent(e, quit, REPLAY2, page);
	backButton.handleEvent(e, quit, BACK, page);
}

void winMenu::renderMenu(SDL_Renderer* renderer)
{
    backgroundMenu.render(renderer, NULL);
    replayButton.button.setRect( buttonX1, buttonY1, buttonW1, buttonH1 );
    replayButton.setPosition( buttonX1, buttonY1 );
    replayButton.renderButton(renderer);
    backButton.button.setRect( buttonX2, buttonY2, buttonW2, buttonH2 );
    backButton.setPosition( buttonX2, buttonY2 );
    backButton.renderButton(renderer);
}




pauseMenu::pauseMenu()
{

}

bool pauseMenu::loadMenu(SDL_Renderer* renderer)
{
    bool flag1 = backgroundMenu.loadImage("image/Menu/pauseMenu.png", renderer);
    bool flag2 = resumeButton.button.loadImage("image/Buttons/resumeButton.png", renderer);
    bool flag3 = backButton.button.loadImage("image/Buttons/backButton.png", renderer);
    if (flag1 == false || flag2 == false || flag3 == false) return false;
    else return true;
}

void pauseMenu::handleEvent( SDL_Event* e, bool& quit, int &page, int level)
{
    backButton.handleEvent(e, quit, BACK, page);
	if (level == 1) resumeButton.handleEvent(e, quit, RESUME1, page);
	else resumeButton.handleEvent(e, quit, RESUME2, page);
}

void pauseMenu::renderMenu(SDL_Renderer* renderer)
{
    backgroundMenu.render(renderer, NULL);
    resumeButton.button.setRect( buttonX1, buttonY1, buttonW1, buttonH1 );
    resumeButton.setPosition( buttonX1, buttonY1 );
    resumeButton.renderButton(renderer);
    backButton.button.setRect( buttonX2, buttonY2, buttonW2, buttonH2 );
    backButton.setPosition( buttonX2, buttonY2 );
    backButton.renderButton(renderer);
}
