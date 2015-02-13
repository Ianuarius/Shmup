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
	int waitTime = 5000;

	window->clear();
	splash_background.render(0, 0);
	window->refresh();

	do {
		waitTime = -10;
		SDL_Delay(10);
	} while(Input::keyState(SDL_SCANCODE_ESCAPE) || waitTime > 0);

}