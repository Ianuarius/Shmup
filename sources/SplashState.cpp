#include "SplashState.h"

SplashState::SplashState(Window *window):
	window(window)
{
	printf ("SplashState.cpp this is Splash state\n");
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
	gameArea.w = window->width;
	gameArea.h = window->height;
}

int SplashState::unload()
{
	return 0;
}

void SplashState::render()
{
	window->drawRect(0, 0, 50, 50, 0xFF00FF);
}