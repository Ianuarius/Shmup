/*
 * Enemy.cpp
 *
 */

#include "Enemy.h"

Enemy::Enemy(Animation* animation, SDL_Rect hitbox, int initialHitPoints):
	MovingEntity(animation, hitbox),
	index(0)
{
	setX(230);
	setY(120);
}

Enemy::~Enemy()
{
}

void Enemy::render() {
	MovingEntity::render();
}

void Enemy::linearPattern()
{
	int linear[] = {LEFT};
	pattern.assign(linear, linear+1);
}

void Enemy::sinePattern(int index)
{
	int sine[] = {UP, UP, UP, DOWN, DOWN, DOWN};
	int shuf[6] = {};

	for (int i = 0; i < 6; i++) {
		shuf[i] = sine[i+index % 6];
	}

	pattern.assign(shuf, shuf+6);
}

void Enemy::update()
{
	chilltime = (++chilltime % 5);

	if (chilltime == 0) {
		index = ((++index) % pattern.size());
	}

	move(pattern[index]);
	move(LEFT);
}