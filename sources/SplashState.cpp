/**
 * SplashState.cpp
 *
 */

#include "SplashState.h"

SplashState::SplashState(Window *window):
	State(),
	splash_texture(window, "images//splashbg.png"),
	window(window) {
}

int SplashState::update() {
	
	if (Input::keyState(SDL_SCANCODE_ESCAPE)) {
		return QUIT_STATE;
	}

	Input::update();
	
	if (Input::keyState(SDL_SCANCODE_RETURN)) {
		return GAME_STATE;
	}

	return SPLASH_STATE;
}

void SplashState::render() {
	window->clear();
	splash_texture.render(0, 0);
	window->refresh();
}