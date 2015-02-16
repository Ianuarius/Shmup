#include "StateManager.h"

StateManager::StateManager(Window *window):
	window(window),
	currentState(nullptr),
	sharedInfo(0)
{
	SplashState splash(window, this);
	sharedInfo = 0;
}

StateManager::~StateManager()
{
	if(currentState)
	{
		currentState->unload();
		currentState = nullptr;
	}
}

void StateManager::run(int state)
{

	switch (state)
	{
	case QUIT:
		break;
	case INGAME:
		break;
	case SPLASH:
		splash.load(0);
		break;
	case SCORE:
		break;
	default:
		break;
	}
}