#include "render.h"

const int backgroundClipX = 0;
const int backgroundClipY = 448;
const int backgroundClipW = 1024;
const int backgroundClipH = 576;

const int groundClipX = 148;
const int groundClipY = 2;
const int groundClipW = 256;
const int groundClipH = 256;

const int backgroundX = 0;
const int backgroundY = 0;
const int backgroundW = 1024;
const int backgroundH = 576;

const int groundX = 0;
const int groundY = 432;
const int groundW = 216;
const int groundH = 216;

const int lineX = 0;
const int lineY = 431;
const int lineW = 1024;
const int lineH = 2;

const int playerX = 300;
const int fallVelocity = 10;

const int backgroundScroll = 1;
const int groundScroll = 8;

render::render()
{

}

render::~render()
{
    gBackground.free();
    gGround.free();
    gLine.free();
    gText.free();
}

render::render(SDL_Renderer* renderer, int level)
{
    bg = {backgroundClipX, backgroundClipY, backgroundClipW, backgroundClipH};
    gr = {groundClipX, groundClipY, groundClipW, groundClipH};
    gBackground.setRect(backgroundX, backgroundY, backgroundW, backgroundH);
    gGround.setRect(groundX, groundY, groundW, groundH);
    gMap.setObject(level);
}

void render::setBackground(SDL_Renderer* renderer)
{
    clip = &bg;
    gBackground.rect_.h = SCREEN_HEIGHT;
    gBackground.rect_.x -= backgroundScroll;
    if (gBackground.rect_.x <= -backgroundW) gBackground.rect_.x = 0;
    gBackground.render(renderer, clip);
    gBackground.rect_.x += backgroundW;
    gBackground.render(renderer, clip);
    gBackground.rect_.x -= backgroundW;
}

void render::setGround(SDL_Renderer* renderer)
{
    clip = &gr;
    gGround.setColor(0, 0, 200);
    gGround.rect_.w = groundW;
    gGround.rect_.x -= groundScroll;
    if (gGround.rect_.x <= -groundW) gGround.rect_.x = 0;
    for (int i = 0; i < 6; i++)
    {
        gGround.render(renderer, clip);
        gGround.rect_.x += groundW;
    }
    gGround.rect_.x -= groundW * 6;
}

void render::setLine(SDL_Renderer* renderer)
{
    gLine.setRect(lineX, lineY, lineW, lineH);
    gLine.render(renderer, NULL);
}

void render::setPlayer(SDL_Renderer* renderer, int input)
{
    gPlayer.gPlayer.rect_.x = playerX;
    gPlayer.gPlayer.rect_.y += fallVelocity;
    gPlayer.update(renderer, input, mode);
}

bool render::loadScene(SDL_Renderer* renderer, int level)
{
    bool flag1 = gBackground.loadImage("image/background.png", renderer);
    bool flag2 = gGround.loadImage("image/ground.png", renderer);
    bool flag3 = gLine.loadImage("image/line.png", renderer);
    bool flag4 = deadEffect.loadImage("image/deadEffect.png", renderer);
    if (flag1 == false || flag2 == false || flag3 == false || flag4 == false) return false;
    if (level == LEVEL1)
    {
        gMusic = Mix_LoadMUS( "audio/sneakyAdventure.wav" );
        if( gMusic == NULL )
        {
            return false;
        }
    }
    else
    {
        gMusic = Mix_LoadMUS( "audio/stereoMadness.wav" );
        if( gMusic == NULL )
        {
            return false;
        }
    }
	gDeadSound = Mix_LoadWAV( "audio/explode_11.wav" );
	if( gDeadSound == NULL )
	{
		return false;
	}
    return true;
}

void render::drawScene(SDL_Renderer* renderer, int input, bool &quit, int &page)
{
    setBackground(renderer);
    setGround(renderer);
    setLine(renderer);
    setPlayer(renderer, input);
    if( Mix_PlayingMusic() == 0 )
    {
        Mix_PlayMusic( gMusic, -1 );
    }
    int countObject = 0;
    for (int i = 0; i < gMap.od.size(); i++)
        {
            int temp = gMap.od[i].objectX + MAP_X;
            if (i == gMap.od.size() - 1 && temp < -300)
            {
                page = WIN_MENU;
                Mix_HaltMusic();
                MAP_X = 1000;
                mode = CUBE;
            }
            if (temp < -42 || temp > 1024)
            {
                continue;
            }
            if (gMap.od[i].objectType >= SMALL_BLOCK && gMap.od[i].objectType <= BLOCK) flag = object.loadImage("image/objects/smallBlocks.png", renderer);
            else if (gMap.od[i].objectType >= SPIKE && gMap.od[i].objectType <= SPIKE_GRASS) flag = object.loadImage("image/objects/spikes.png", renderer);
            else if (gMap.od[i].objectType >= FOUR_SIDES_WINDOW && gMap.od[i].objectType <= TWO_SIDES_BLOCK) flag = object.loadImage("image/objects/spritesheet.png", renderer);
            else flag = object.loadImage("image/objects/portal.png", renderer);
            object.rect_ = gMap.od[i].objectRect;
            object.rect_.x += MAP_X;
            gMap.clip_ = &gMap.clips[gMap.od[i].objectType];
            object.renderWithRotation(renderer, gMap.clip_, gMap.od[i].objectAngle);
            if (!gPlayer.collisions(object.rect_, gMap.od[i].objectType, mode))
            {
                MAP_X = 1000 ;
                Mix_PlayChannel( -1, gDeadSound, 0 );
                Mix_HaltMusic();
                mode = CUBE;
                SDL_Delay(500);
            }
            countObject++;
        }
    MAP_X -= 10;
    float delay = 96/(countObject + 8);
    if (countObject > 12) delay = 1;
    SDL_Delay(delay);
}

