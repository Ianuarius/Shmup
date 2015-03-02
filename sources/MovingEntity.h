/*
 * MovingEntity.h
 * 
 * T�m� luokka on yl�luokka kaikille entityille, joita voi vahingoittaa, 
 * eli, joilla on health pointit.
 * 
 * Esimerkki:
 *		MovingEntity movingEntity = new MovingEntity();
 *		movingEntity->metodi();
 */

#ifndef __MOVINGENTITY_H_DEFINED__
#define __MOVINGENTITY_H_DEFINED__

#include "Entity.h"
#include "Texture.h"
#include "Sprite.h"
#include "Animation.h"
#include "Level.h"

class MovingEntity : public Entity
{
	public:
		MovingEntity(Texture *sprite, SDL_Rect hitbox);
		MovingEntity(Sprite *sprite, SDL_Rect hitbox);
		MovingEntity(Animation *sprite, SDL_Rect hitbox);
		~MovingEntity();

		enum DIRECTION {
			UP,
			DOWN,
			LEFT,
			RIGHT
		};

		void move(int direction);
		void speed(int speed);

		int getSpeed();

		SDL_bool collides(Entity *other);
		SDL_bool collides(Level *level);

	private:
		int _speed;
};

#endif // __MOVINGENTITY_H_DEFINED__