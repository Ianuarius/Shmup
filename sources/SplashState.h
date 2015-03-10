/**
 * SplashState.h
 *
 * Description:
 * State displaying the Splash Screen.
 *
 * Example:
 * --
 */

#ifndef __SPLASHSTATE_H_DEFINED__
#define __SPLASHSTATE_H_DEFINED__

#include "State.h"
#include "Window.h"
#include "Texture.h"

class SplashState: public State {
public:
	SplashState(Window *window);
	int update();
	void render();

private:
	Window *window;
	Texture splash_texture;
};

#endif