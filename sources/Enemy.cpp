/*
 * Enemy.cpp
 *
 */

#include "Enemy.h"

Enemy::Enemy(Animation *animation, Animation *dyingAnimation, SDL_Rect hitbox, int initialHitPoints):
	MovingEntity(animation, hitbox),
	DamageableEntity(1),
	dyingAnimation(dyingAnimation),
	index(0),
	norender(false)
{
	MovingEntity::setX(230);
	MovingEntity::setY(120);
}

Enemy::~Enemy()
{
}

void Enemy::render() {
	if (!norender) {
		MovingEntity::render();
	}
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
	if (isDead()) {
		MovingEntity::speed(2);
		MovingEntity::move(LEFT);

		if (MovingEntity::animation != dyingAnimation) {
			MovingEntity::animation = dyingAnimation;
			MovingEntity::animation->play(1);
		}

		if (MovingEntity::animation->done()) {
			norender = true;
		}

		return;
	} else {
		chilltime = (++chilltime % 5);

		if (chilltime == 0) {
			index = ((++index) % pattern.size());
		}

		move(pattern[index]);
		move(LEFT);
	}
}