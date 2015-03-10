/*
 * MovingEntity.cpp
 *
 */

#include "MovingEntity.h"

MovingEntity::MovingEntity(Texture *sprite, SDL_Rect hitbox) :
	Entity(sprite, hitbox),
	_speed(1)
{
}

MovingEntity::MovingEntity(Sprite *sprite, SDL_Rect hitbox) :
	Entity(sprite, hitbox),
	_speed(1)
{
}

MovingEntity::MovingEntity(Animation *sprite, SDL_Rect hitbox) :
	Entity(sprite, hitbox),
	_speed(1)
{
}

MovingEntity::~MovingEntity()
{
}

void MovingEntity::move(int direction)
{
	if (direction == UP) {
		//desiredY -= _speed;
		this->y -= _speed;
		this->hitbox.y = y;
		//printf("Sprite x%d\\y%d\tHitbox x%d\\y%d\n", x, y, hitbox.x, hitbox.y);
	}

	if (direction == DOWN) {
		//desiredY += _speed;
		this->y += _speed;
		this->hitbox.y = y;
		//printf("Sprite x%d\\y%d\tHitbox x%d\\y%d\n", x, y, hitbox.x, hitbox.y);
	}

	if (direction == LEFT) {
		//desiredX -= _speed;
		this->x -= _speed;
		this->hitbox.x = x;
		//printf("Sprite x%d\\y%d\tHitbox x%d\\y%d\n", x, y, hitbox.x, hitbox.y);
	}

	if (direction == RIGHT) {
		//desiredX += _speed;
		this->x += _speed;
		this->hitbox.x = x;
		//printf("Sprite x%d\\y%d\atHitbox x%d\\y%d\n", x, y, hitbox.x, hitbox.y);
	}
}

void MovingEntity::speed(int speed) {
	_speed = speed;
}

bool MovingEntity::collides(Entity *other)
{
	SDL_Rect result;

	if (SDL_IntersectRect(&hitbox, &other->hitbox, &result)) {
		//printf("w%d h%d x%d y%d", result.w, result.h, result.x, result.y);
		//this->x -= result.w;
		//this->y -= result.h;

		//hitbox.x -= result.w;
		//hitbox.y -= result.h;

		return true;
	}

	return false;
}

int MovingEntity::getSpeed()
{
	return _speed;
}