/*
 * Entity.cpp
 *
 */

#include "entity.h"

Entity::Entity(Sprite *sprite, SDL_Rect hitbox):
	sprite(sprite),
	x(0),
	y(0),
	hitbox(hitbox)
{
	

}

Entity::~Entity()
{

}

void Entity::render()
{
	sprite->render(0, x, y);
}

void Entity::update(int x, int y)
{
	this->x += x;
	this->y += y;
	this->hitbox.x = hitbox.x+x;
	this->hitbox.y = hitbox.y+y;
}

SDL_bool Entity::collides(Entity *other)
{
	SDL_Rect result;
	
	return SDL_IntersectRect(&hitbox, &other->hitbox, &result);
}

SDL_bool Entity::collides(Level *level)
{
	int hbX;
	int hbY;

	// Palauttaa hitboxin vasemman yläkulman tilen
	hbX = hitbox.x;
	hbY = hitbox.y;

	if(level->getTile(hbX, hbY) != 1){
		return SDL_TRUE;
	}

	hbX = hitbox.x + hitbox.w;
	hbY = hitbox.y;

	if(level->getTile(hbX, hbY) != 1){
		return SDL_TRUE;
	}

	hbX = hitbox.x + hitbox.w;
	hbY = hitbox.y + hitbox.h;

	if(level->getTile(hbX, hbY) != 1){
		return SDL_TRUE;
	}

	hbX = hitbox.x;
	hbY = hitbox.y + hitbox.h;

	if(level->getTile(hbX, hbY) != 1){
		return SDL_TRUE;
	}
	
	return SDL_FALSE;
}

int Entity::getX(){
	return x; 
}

int Entity::getY(){
	return y;
}