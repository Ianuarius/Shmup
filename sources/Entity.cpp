/*
 * Entity.cpp
 *
 */

#include "Entity.h"

Entity::Entity(Texture *texture, SDL_Rect hitbox, int x, int y):
	texture(texture),
	sprite(nullptr),
	animation(nullptr),
	x(x),
	y(y),
	hitbox(hitbox),
	frame(0)
{

}

Entity::Entity(Sprite *sprite, SDL_Rect hitbox, int x, int y):
	texture(nullptr),
	sprite(sprite),
	animation(nullptr),
	x(x),
	y(y),
	hitbox(hitbox),
	frame(0)
{

}

Entity::Entity(Animation *animation, SDL_Rect hitbox, int x, int y):
	texture(nullptr),
	sprite(nullptr),
	animation(animation),
	x(x),
	y(y),
	hitbox(hitbox)
{
//	sprite = animation->animated;
//	frame = animation->getFrame();
}

Entity::~Entity()
{

}

void Entity::render()
{
	if (texture) {
		texture->render(x, y);
	}

	if (sprite) {
		sprite->render(x, y);
	}

	if (animation) {
		animation->render(x, y);
	}
}


int Entity::getX()
{
	return x; 
}

int Entity::getY()
{
	return y;
}

void Entity::setX(int x) {
	this->x = x;
}

void Entity::setY(int y) {
	this->y = y;
}