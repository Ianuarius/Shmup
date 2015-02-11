/*
 * Player.cpp
 *
 */

#include "player.h"

Player::Player(Animation *animation, SDL_Rect hitbox, int initialHitPoints): 
	DamageableEntity(animation, hitbox, initialHitPoints),
	MovingEntity(animation, hitbox)
{
}

Player::~Player()
{
}

void Player::render()
{
}