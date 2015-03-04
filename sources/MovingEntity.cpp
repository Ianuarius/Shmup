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
		this->y -= _speed;
		this->hitbox.y = hitbox.y+y;
	}

	if (direction == DOWN) {
		this->y += _speed;
		this->hitbox.y = hitbox.y+y;
	}

	if (direction == LEFT) {
		this->x -= _speed;
		this->hitbox.x = hitbox.x+x;
	}

	if (direction == RIGHT) {
		this->x += _speed;
		this->hitbox.x = hitbox.x+x;
	}
}

void MovingEntity::speed(int speed) {
	_speed = speed;
}

SDL_bool MovingEntity::collides(Entity *other)
{
	SDL_Rect result;
	
	return SDL_IntersectRect(&hitbox, &other->hitbox, &result);
}

/*
SDL_bool MovingEntity::collides(Level *level)
{
	int hbX;
	int hbY;

	// Palauttaa hitboxin vasemman yläkulman tilen
	hbX = hitbox.x;
	hbY = hitbox.y;
	printf("Hitbox %d/%d\n", hitbox.x, hitbox.y);
	printf("GETTILE: %d\n", level->getTile(hbX, hbY));

	if(level->getTile(hbX, hbY) != 1)
	{
		return SDL_TRUE;
	}

	// Palauttaa hitboxin oikean yläkulman tilen
	hbX = hitbox.x + hitbox.w;
	hbY = hitbox.y;

	if(level->getTile(hbX, hbY) != 1){
		return SDL_TRUE;
	}

	// Palauttaa hitboxin vasemman alakulman tilen
	hbX = hitbox.x + hitbox.w;
	hbY = hitbox.y + hitbox.h;

	if(level->getTile(hbX, hbY) != 1){
		return SDL_TRUE;
	}

	// Palauttaa hitboxin oikean alakulman tilen
	hbX = hitbox.x;
	hbY = hitbox.y + hitbox.h;

	if(level->getTile(hbX, hbY) != 1){
		return SDL_TRUE;
	}
	
	return SDL_FALSE;
}
*/

int MovingEntity::getSpeed()
{
	return _speed;
}