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

#ifndef __MOVINGENTITY_H_DEFINED__
#define __MOVINGENTITY_H_DEFINED__

#include "Entity.h"
#include "Texture.h"
#include "Sprite.h"
#include "Animation.h"

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

		bool collides(Entity *other);

	private:
		int _speed;
		int desiredX, desiredY;
};

#endif // __MOVINGENTITY_H_DEFINED__