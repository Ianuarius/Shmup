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

class Entity
{
public:
	Entity(Sprite *sprite, SDL_Rect hitbox);
	~Entity();

	void render();
	void update(int x, int y);
	SDL_bool collides(Entity *other);
	SDL_bool collides(Level *level);

	SDL_Rect hitbox;

	int getX();
	int getY();

private:
	int x, y;
	Sprite *sprite;
};

#endif //__ENTITY_H_DEFINED__