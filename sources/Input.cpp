/*
 * Input.cpp
 *
 */

#include "input.h"

bool Input::key[KEYBOARD_SIZE] = {0};
bool Input::isLocked = false;

const Uint8* Input::keyboard = NULL;

void Input::update() {	
	SDL_Event event;

	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_KEYDOWN: {
					keyboard = SDL_GetKeyboardState(nullptr);

					int scancode = event.key.keysym.scancode;
					key[scancode] = true;
				}
				break;

			case SDL_KEYUP: {
					keyboard = SDL_GetKeyboardState(nullptr);

					int scancode = event.key.keysym.scancode;
					key[scancode] = false;
				}
				break;

			default:
				break;
		}
	}
}

bool Input::keyState(int k) {
	if(isLocked) {
		return false;
	}

	if(k < 0 || k >= KEYBOARD_SIZE) {
		return false;
	}

	return key[k];
}

bool Input::alt() {
	return keyState(SDL_SCANCODE_LALT) || keyState(SDL_SCANCODE_RALT);
}

bool Input::ctrl() {
	return keyState(SDL_SCANCODE_LCTRL) || keyState(SDL_SCANCODE_RCTRL);
}

bool Input::shift() {
	return keyState(SDL_SCANCODE_LSHIFT) || keyState(SDL_SCANCODE_RSHIFT);
}

void Input::lock() {
	isLocked = true;
}

void Input::unlock() {
	isLocked = false;
}