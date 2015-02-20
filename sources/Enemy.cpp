/*
 * Enemy.cpp
 *
 */

#include "enemy.h"

Enemy::Enemy(Animation *animation, SDL_Rect hitbox, int initialHitPoints): 
	DamageableEntity(animation, hitbox, initialHitPoints),
	MovingEntity(animation, hitbox)
{
	MovingEntity::setX(240);
	MovingEntity::setY(120);
}

Enemy::~Enemy()
{
}

void Enemy::render() {
	MovingEntity::render();
}