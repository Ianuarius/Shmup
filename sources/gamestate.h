#ifndef __GAMESTATE_H_INCLUDED__
#define __GAMESTATE_H_INCLUDED__

#include <stdio.h>
#include "state.h"
#include "window.h"

class GameState: public State
{
public:
	GameState(Window *window);
	void render();
	void load();

private:
	Window *window;

};

#endif // __STATE_H_INCLUDED__
