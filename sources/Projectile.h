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
	Projectile(Window *window);
	~Projectile();
	
	void spawn(int type, int x, int y, int radian);

	// Iterates through container
	void update();

	// Renders all objects in container
	void render();

private:
	Window *window;
	Sprite bullet_texture;

	struct bullet {
		MovingEntity entity;
		int radian;
		int type;
	};


	// All bullet instances
	std::vector<bullet> container;
};

#endif //__PROJECTILE_H_DEFINED__