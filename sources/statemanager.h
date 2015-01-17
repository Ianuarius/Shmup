#ifndef __STATEMANAGER_H_INCLUDED__
#define __STATEMANAGER_H_INCLUDED__

#include <stdio.h>
#include "state.h"
#include "gamestate.h"

class StateManager
{
public:
	StateManager(Window *window);
	~StateManager();

	void run();

private:
	Window *window;
	State *currentState;
	int sharedInfo;
};

#endif // __STATEMANAGER_H_INCLUDED__
