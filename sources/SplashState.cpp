#include "SplashState.h"

SplashState::SplashState(Window *window):
	window(window),
	splash_background(window, "splashbg.png")
{
}

SplashState::~SplashState()
{
}

void SplashState::load(int stack)
{
	UNUSED(stack);


	SDL_Rect gameArea;

	gameArea.x = 0;
	gameArea.y = 0;
	gameArea.w = 256;
	gameArea.h = 240;
}

int SplashState::unload()
{
	return 0;
}

void SplashState::render()
{
	splash_background.render(0, 0);
}