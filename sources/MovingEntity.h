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
		SDL_bool collides(Entity *other);
		SDL_bool collides(Level *level);

	private:
		int _speed;

};

#endif //__MOVINGENTITY_H_DEFINED__