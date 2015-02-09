/*
 * MovingEntity.h
 * 
 * Tämä luokka on yläluokka kaikille entityille, joita voi vahingoittaa, 
 * eli, joilla on health pointit.
 * 
 * Esimerkki:
 *		MovingEntity movingEntity = new MovingEntity();
 *		movingEntity->metodi();
 */

#ifndef MOVINGENTITY_H_DEFINED
#define MOVINGENTITY_H_DEFINED

#include "SDL.h"
#include "Window.h"
#include "Sprite.h"
#include "Entity.h"
#include "Animation.h"

class MovingEntity : public Entity
{
public:
	MovingEntity(Sprite *sprite, SDL_Rect hitbox);
	MovingEntity(Animation *sprite, SDL_Rect hitbox);
	~MovingEntity();

	void move(int x, int y);
	SDL_bool collides(Entity *other);
	SDL_bool collides(Level *level);

private:
};

#endif //__MOVINGENTITY_H_DEFINED__