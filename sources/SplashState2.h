#ifndef __SPLASHSTATE_H_INCLUDED__
#define __SPLASHSTATE_H_INCLUDED__

#include <stdio.h>
#include "state.h"
#include "window.h"
#include "sdl.h"
#include "sprite.h"

class SplashState: public State
{
public:
	SplashState(Window *window);
	virtual ~SplashState();

	void load(int stack);
	int unload();
	void render();

private:
	Window *window;
	SDL_Rect gameArea;

};

#endif // __SPLASHSTATE_H_INCLUDED__