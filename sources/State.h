#ifndef __STATE_H_INCLUDED__
#define __STATE_H_INCLUDED__

#include "StateManager.h"

class State
{
public:
	virtual State (Window *window, StateManager *manager) {};
	virtual ~State() {};
	virtual void load(int stack = 0) = 0;
	virtual int unload() = 0;

private:
	Window *window;
	StateManager *manager;
};

#endif // __STATE_H_INCLUDED__
