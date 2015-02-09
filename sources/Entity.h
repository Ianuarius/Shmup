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

#ifndef ENTITY_H_DEFINED
#define ENTITY_H_DEFINED

#include "SDL.h"
#include "Sprite.h"
#include "Level.h"
#include "Animation.h"

class Entity
{
public:
	Entity(Sprite *sprite, SDL_Rect hitbox, int x = 0, int y = 0);
	Entity(Animation *sprite, SDL_Rect hitbox, int x = 0, int y = 0);
	~Entity();

	void render();

	int getX();
	int getY();
	SDL_Rect hitbox;

protected:
	int x, y, frame;
	Sprite *sprite;
	Animation *anime;

};

#endif //__ENTITY_H_DEFINED__