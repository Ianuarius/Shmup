/*
 * Entity.h
 * 
 * Tämä luokka on yläluokka kaikille pelin entiteeteille, joita voivat olla
 * esimerkiksi, pelaaja, viholliset ja ammukset.
 * 
 * Esimerkki:
 *		Entity entity = new Entity();
 *		entity->metodi();
 */

#ifndef __ENTITY_H_DEFINED__
#define __ENTITY_H_DEFINED__

#include "Texture.h"
#include "Sprite.h"
#include "Animation.h"

class Entity
{
public:
	Entity(Texture *texture, SDL_Rect hitbox, int x = 0, int y = 0);
	Entity(Sprite *sprite, SDL_Rect hitbox, int x = 0, int y = 0);
	Entity(Animation *animation, SDL_Rect hitbox, int x = 0, int y = 0);
	~Entity();

	void render();
	Animation *animation;

	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	SDL_Rect hitbox;

protected:
	int x, y, frame, index;
	Texture *texture;
	Sprite *sprite;
};

#endif //__ENTITY_H_DEFINED__