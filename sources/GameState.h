/**
 * GameState.h
 *
 * Description:
 * State where the game is happening.
 *
 * Example:
 * --
 */

#ifndef __GAMESTATE_H_DEFINED__
#define __GAMESTATE_H_DEFINED__

#include "State.h"
#include "Player.h"
#include "Level.h"

class GameState : public State {
public:
	GameState(Window *window);
	int update();
	void render();

private:
	Level level;
	Player player;
	Window *window;
};

#endif