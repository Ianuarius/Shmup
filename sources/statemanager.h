#ifndef __STATEMANAGER_H_INCLUDED__
#define __STATEMANAGER_H_INCLUDED__

#include <stdio.h>
#include "state.h"
#include "gamestate.h"

class StateManager
{
public:
	StateManager(Window *window);
	void run();

private:
	Window *window;
	State *currentState;

	//TODO(juha): jos halutaan siirt‰‰ tietoja statejen v‰lill‰, niin siihen jotain (esim. pausesta paluu).
};

#endif // __STATEMANAGER_H_INCLUDED__
