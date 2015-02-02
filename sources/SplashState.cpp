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
	gameArea.w = 256;
	gameArea.h = 240;
}

int SplashState::unload()
{
	return 0;
}

void SplashState::render()
{
	// NOTE(juha): Täällä määritellään, mitä halutaan Staten piirtävän.
	// window->drawRect(0, 0, 50, 50, 0xFF00FF); // Piirtää pinkin neliön
	//SDL_Point center;
	//center.x = 50;
	//center.y = 50;
	//window->loadImage("testpic.png");
	//window->render(0, 0, &gameArea, 0, &center, SDL_FLIP_NONE);
}