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
#include "Sprite.h"
#include "MovingEntity.h"

class Projectile
{
	public:
		Projectile(Window *window, int type, int x, int y, int radian);
		~Projectile();

		// Iterates through container
		void update();

		// Renders all objects in container
		void render();

	private:
		int radian, x, y, vx, vy;
		static SDL_Rect empty = {0, 0, 0, 0};
};

#endif //__PROJECTILE_H_DEFINED__