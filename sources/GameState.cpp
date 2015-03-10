/**
 * GameState.cpp
 *
 */

#include "GameState.h"

GameState::GameState(Window *window):
	State(),
	window(window),
	level(window),
	player(window) {
		level.load("levels//level_city_vol_01.tmx");
}

int GameState::update() {
	

	if (Input::keyState(SDL_SCANCODE_ESCAPE)) {
		return QUIT_STATE;
	}

	Input::update();
	
	player.update();

	return GAME_STATE;
}

void GameState::render() {
	
	window->clear();
	level.render();
	player.render();
	window->refresh();

}