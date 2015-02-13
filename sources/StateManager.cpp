#include "StateManager.h"

StateManager::StateManager(Window *window):
	window(window),
	currentState(nullptr),
	sharedInfo(0)
{
	currentState = new SplashState(window);
	currentState->load();
	sharedInfo = 0;
}

StateManager::~StateManager()
{
	if(currentState)
	{
		currentState->unload();
		delete currentState;

		currentState = nullptr;
	}
}

void StateManager::run(int state)
{
		SplashState splash(window);
	switch (state)
	{
	case QUIT:
		break;
	case INGAME:
		break;
	case SPLASH:
		splash.render();
		break;
	case SCORE:
		break;
	default:
		break;
	}
}