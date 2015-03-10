/**
 * State.h
 *
 * Description:
 * Abstract base class for all the states.
 *
 * Example:
 * --
 */

#ifndef __STATE_H_DEFINED__
#define __STATE_H_DEFINED__

#include "Input.h"

#define SPLASH_STATE 1
#define GAME_STATE   2
#define QUIT_STATE   3

class State {
public:
	State() {}
	virtual int update() = 0;
	virtual void render() = 0;

protected:
};

#endif