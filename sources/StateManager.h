#ifndef __STATEMANAGER_H_INCLUDED__
#define __STATEMANAGER_H_INCLUDED__

#include <stdio.h>
#include "State.h"
#include "GameState.h"
#include "SplashState.h"
#include "SDL.h"
#include "Window.h"

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
