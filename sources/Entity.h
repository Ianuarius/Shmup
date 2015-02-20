/*
 * Entity.h
 * 
 * T�m� luokka on yl�luokka kaikille pelin entiteeteille, joita voivat olla
 * esimerkiksi, pelaaja, viholliset ja ammukset.
 * 
 * Esimerkki:
 *		Entity entity = new Entity();
 *		entity->metodi();
 */

#ifndef ENTITY_H_DEFINED
#define ENTITY_H_DEFINED

#include "SDL.h"
#include "Texture.h"
#include "Sprite.h"
#include "Animation.h"
#include "Level.h"

class Entity
{
public:
	Entity(Texture *texture, SDL_Rect hitbox, int x = 0, int y = 0);
	Entity(Sprite *sprite, SDL_Rect hitbox, int x = 0, int y = 0);
	Entity(Animation *animation, SDL_Rect hitbox, int x = 0, int y = 0);
	~Entity();

	void render();

	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	SDL_Rect hitbox;

protected:
	int x, y, frame, index;
	Texture *texture;
	Sprite *sprite;
	Animation *animation;
};

#endif //__ENTITY_H_DEFINED__