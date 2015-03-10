/**
 * StateManager.cpp
 *
 */

#include "StateManager.h"

StateManager::StateManager(Window *window):
	window(window),
	current_state(nullptr),
	status(0) {
		changeState();
}

void StateManager::changeState() {
	if (status == 0 || status == SPLASH_STATE) {
		if (current_state) {
			delete current_state;
		}
		current_state = nullptr;
		current_state = new SplashState(window);
	}
	else if (status == GAME_STATE) {
		delete current_state;
		current_state = nullptr;
		current_state = new GameState(window);
	}
	else if (status == QUIT_STATE) {
		delete current_state;
		current_state = nullptr;
	}
}

void StateManager::update() {
	status = current_state->update();

	// TODO(juha): delete GameState when the player dies.
}

void StateManager::render() {
	current_state->render();
}

int StateManager::getState() {
	return status;
}