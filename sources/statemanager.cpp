#include "statemanager.h"
#include "SplashState.h"
#include "sdl.h"
#include "window.h"

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

void StateManager::run()
{
	printf("statemanager.cpp: Nyt ollaan StateManagerin runissa\n");

	bool quit = false;

	while(!quit)
	{
		window->clear();
		currentState->render();
		window->refresh();
	}
}