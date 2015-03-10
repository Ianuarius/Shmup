/**
 * StateManager.h
 *
 * Description:
 * Switches states around depending on the status of the game. The states that
 * the StateManager manages tell it what state to run next.
 *
 * Example:
 * StateManager manager(&window);
 * manager.update();
 * manager.render();
 */

#ifndef __STATEMANAGER_H_DEFINED__
#define __STATEMANAGER_H_DEFINED__

#include "Window.h"
#include "State.h"
#include "SplashState.h"
#include "GameState.h"

#define SPLASH_STATE 1
#define GAME_STATE   2
#define QUIT_STATE   3

class StateManager {
public:
	StateManager(Window *window);

	// Updates and renders the current state.
	void update();
	void render();

	// Returns the code of the state.
	int getState();

	// Switches the current state to the one defined in status member.
	void changeState();
	
private:
	State *current_state;
	Window *window;
	int status;
};

#endif