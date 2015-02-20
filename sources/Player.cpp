/*
 * Player.cpp
 *
 */

#include "player.h"

Player::Player(Window *window):
	animation(window, "player_spritesheet.png", 32, 32, 0, 4, 2),
	DamageableEntity(&animation, hitbox, 10),
	MovingEntity(&animation, hitbox)
{
	MovingEntity::speed(5);
}

Player::~Player()
{
}

void Player::update()
{
	if (Input::keyState(SDL_SCANCODE_W)) {
		move(0);
	}

	if (Input::keyState(SDL_SCANCODE_A)) {
		move(2);
	}

	if (Input::keyState(SDL_SCANCODE_S)) {
		move(1);
	}

	if (Input::keyState(SDL_SCANCODE_D)) {
		move(3);
	}
}

void Player::render() {
	MovingEntity::render();
}