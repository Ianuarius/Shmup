#include "statemanager.h"

StateManager::StateManager(Window *window):
	window(window),
	currentState(nullptr)
{

}

void StateManager::run()
{
	printf("statemanager.cpp i manage states\n");
	this->currentState = new GameState(window);
	this->currentState->load();
}