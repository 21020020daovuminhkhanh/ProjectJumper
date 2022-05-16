#include "render.h"



render::render()
{

}

render::~render()
{
    gBackground.free();
    gGround.free();
    gLine.free();
}

render::render(SDL_Renderer* renderer, int level)
{
    bg = {0, 448, 1024, 576};
    gr = {148, 2, 256, 256};
    gBackground.setRect(0, 0, 1024, 576);
    gGround.setRect(0, 432, 216, 216);
    gMap.setObject(level);
    SDL_LoadWAV("audio/stereoMadness.wav", &wavSpec, &wavBuffer, &wavLength);
	SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
	SDL_QueueAudio(deviceId, wavBuffer, wavLength);
	SDL_PauseAudioDevice(deviceId, 0);
}

void render::setBackground(SDL_Renderer* renderer)
{
    clip = &bg;
    gBackground.rect_.h = SCREEN_HEIGHT;
    gBackground.rect_.x -= 1;
    if (gBackground.rect_.x <= -1024) gBackground.rect_.x = 0;
    gBackground.render(renderer, clip);
    gBackground.rect_.x += 1024;
    gBackground.render(renderer, clip);
    gBackground.rect_.x -= 1024;
}

void render::setGround(SDL_Renderer* renderer)
{
    clip = &gr;
    gGround.setColor(0, 0, 200);
    gGround.rect_.w = 216;
    gGround.rect_.x -= 8;
    if (gGround.rect_.x <= -216) gGround.rect_.x = 0;
    for (int i = 0; i < 6; i++)
    {
        gGround.render(renderer, clip);
        gGround.rect_.x += 216;
    }
    gGround.rect_.x -= 1296;
}

void render::setLine(SDL_Renderer* renderer)
{
    gLine.setRect(0, 431, 1024, 2);
    gLine.render(renderer, NULL);
}

void render::setPlayer(SDL_Renderer* renderer, int input)
{
    gPlayer.gPlayer.rect_.y += 10;
    gPlayer.gPlayer.rect_.w = 42;
    gPlayer.gPlayer.rect_.h = 42;
    gPlayer.gPlayer.rect_.x = 300;
    gPlayer.update(renderer, input, 0);
}


bool render::loadScene(SDL_Renderer* renderer)
{
    bool flag1 = gBackground.loadImage("image/bg01.png", renderer);
    bool flag2 = gGround.loadImage("image/ground.png", renderer);
    bool flag3 = gLine.loadImage("image/line.png", renderer);
    bool flag4 = gPlayer.gPlayer.loadImage("image/player.png", renderer);
    if (flag1 == false || flag2 == false || flag3 == false || flag4 == false) return false;
    return true;
}

void render::drawScene(SDL_Renderer* renderer, int input, bool &quit)
{
    setBackground(renderer);
    setGround(renderer);
    setLine(renderer);
    setPlayer(renderer, input);
    for (int i = 0; i < gMap.od.size(); i++)
        {
            if (gMap.od[i].objectType >= 0 && gMap.od[i].objectType <= 1) flag = object.loadImage("image/smallBlocks.png", renderer);
            else if (gMap.od[i].objectType >= 2 && gMap.od[i].objectType <= 5) flag = object.loadImage("image/spikes.png", renderer);
            else flag = object.loadImage("image/spritesheet.png", renderer);
            object.rect_ = gMap.od[i].objectRect;
            object.rect_.x += MAP_X;
            if (!gPlayer.collisions(object.rect_, gMap.od[i].objectType))
            {
                MAP_X = 1000 ;
                //quit = true;
                cout << "you die!";
            }
            gMap.clip_ = &gMap.clips[gMap.od[i].objectType];
            if (object.rect_.x >= -42 && object.rect_.x <= 1024)
            {
                object.renderWithRotation(renderer, gMap.clip_, gMap.od[i].objectAngle);
            }
            if (i == gMap.od.size() - 1 && object.rect_.x < -300)
            {
                quit = true;
                cout << "you win !";
            }
        }
    MAP_X -= 10;
}

