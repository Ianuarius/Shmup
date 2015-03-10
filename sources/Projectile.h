/*
 * Projectile.h
 * 
 * Tämä luokka on yläluokka kaikille entityille, joita voi vahingoittaa, 
 * eli, joilla on health pointit.
 * 
 * Esimerkki:
 *		Projectile projectile = new Projectile();
 *		projectile->metodi();
 */

#ifndef __PROJECTILE_H_DEFINED__
#define __PROJECTILE_H_DEFINED__

#include <vector>
#include "SDL.h"
#include "Window.h"
#include "Texture.h"
#include "Sprite.h"
#include "MovingEntity.h"

class Projectile : public MovingEntity
{
	public:
		Projectile(Texture *texture, int speed, int x, int y, int radian);
		~Projectile();

		// Iterates through container
		void update();

		// Renders all objects in container
		void render();

	private:
		int radian, x, y, vx, vy;
		Texture *texture;
		static SDL_Rect hitbox;
};

#endif //__PROJECTILE_H_DEFINED__