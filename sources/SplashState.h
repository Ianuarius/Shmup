#ifndef __SPLASHSTATE_H_INCLUDED__
#define __SPLASHSTATE_H_INCLUDED__

#include <stdio.h>
#include "state.h"
#include "window.h"
#include "sdl.h"
#include "texture.h"
#include "Input.h"

class SplashState: public State
{
public:
	SplashState(Window *window, StateManager *manager);
	virtual ~SplashState();

	void load(int stack);
	int unload();

private:
	SDL_Rect gameArea;
	Texture splash_background;

};

#endif // __SPLASHSTATE_H_INCLUDED__