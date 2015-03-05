/*
 * Player.cpp
 *
 */

#include "player.h"

SDL_Rect Player::hitbox = {0, 0, 32, 32};

Player::Player(Window *window, HUD *hud, EntityCollection<Projectile> *projectiles):
	window(window),
	animation(window, "player_spritesheet.png", 32, 32, 0, 4, 2),
	DamageableEntity(&animation, hitbox, 10),
	MovingEntity(&animation, hitbox),
	hud(hud),
	projectiles(projectiles)
{
	MovingEntity::speed(4);
	ammus = new Texture(window, "ammus.png");
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

	if (Input::keyState(SDL_SCANCODE_SPACE)) {
		Projectile projectile(ammus, 10, getX(), getY(), 0);
		projectiles->push(projectile);
	}

	if (Input::keyState(SDL_SCANCODE_1)) {
		hud->setWeapon(0);
	}

	if (Input::keyState(SDL_SCANCODE_2)) {
		hud->setWeapon(1);
	}

	if (Input::keyState(SDL_SCANCODE_3)) {
		hud->setWeapon(2);
	}

	if (Input::keyState(SDL_SCANCODE_4)) {
		hud->setWeapon(3);
	}

	if (Input::keyState(SDL_SCANCODE_5)) {
		hud->setWeapon(4);
	}

	if (Input::keyState(SDL_SCANCODE_6)) {
		hud->setWeapon(5);
	}

	if (Input::keyState(SDL_SCANCODE_7)) {
		hud->setWeapon(6);
	}

	if (Input::keyState(SDL_SCANCODE_8)) {
		hud->setWeapon(7);
	}
}

void Player::render() {
	MovingEntity::render();
}