/*
 * Player.cpp
 *
 */

#include "player.h"

SDL_Rect Player::hitbox = {0, 0, 32, 32};

Player::Player(Window *window, HUD *hud, EntityCollection<Projectile> *projectiles):
	window(window),
	//animation(window, "player_spritesheet.png", 32, 32, 0, 4, 2),
	currentAnimation(nullptr),
	DamageableEntity(1),
	MovingEntity(currentAnimation, hitbox),
	hud(hud),
	projectiles(projectiles),
	immune(false),
	immunityLength(0),
	norender(false),
	shot(false)
{
	MovingEntity::speed(4);

	ammus = new Texture(window, "ammus.png");

	animations.push_back(new Animation(window, "player_spritesheet.png", 32, 32, 0, 4, 2));
	animations.push_back(new Animation(window, "player_spritesheet_damage.png", 32, 32, 0, 8, 4));
	animations.push_back(new Animation(window, "player_dead.png", 32, 32, 0, 10, 12));

	MovingEntity::animation = animations[0];
}

Player::~Player()
{
}

void Player::update()
{
	if (isDead()) {
		MovingEntity::speed(2);
		MovingEntity::move(LEFT);

		if (MovingEntity::animation != animations[2]) {
			MovingEntity::animation = animations[2];
			MovingEntity::animation->play(1);
		}

		if (MovingEntity::animation->done()) {
			norender = true;
		}

		return;
	}

	if (Input::keyState(SDL_SCANCODE_K)) {
		DamageableEntity::damage(1);
	}

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
		if (!shot) {
			Projectile projectile(ammus, 10, getX()+28, getY()+15, 0);
			projectiles->push(projectile);
			shot = true;
		}
	} else {
		shot = false;
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

	if (immune) {
		if (immunityLength > 0) {
			immunityLength -= window->getDelta();
			printf("Immune for %dms\n", immunityLength);
		} else {
			immune = false;
		}
	}
}

void Player::render() {
	if (!norender) {
		MovingEntity::render();
	}
}

void Player::immunity(int length) {
	immunityLength += length;
	immune = true;
}

bool Player::isImmune() {
	return immune;
}