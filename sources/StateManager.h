#ifndef __STATEMANAGER_H_INCLUDED__
#define __STATEMANAGER_H_INCLUDED__

#include <stdio.h>
#include "state.h"
#include "gamestate.h"
#include "SplashState.h"
#include "sdl.h"
#include "window.h"

class StateManager
{
public:
	
	enum StateCode
	{
		QUIT,
		INGAME,
		SPLASH,
		SCORE
	};

	StateManager(Window *window);
	~StateManager();

	void run(int state);

private:
	Window *window;
	State *currentState;
	int sharedInfo;
};

#endif // __STATEMANAGER_H_INCLUDED__
