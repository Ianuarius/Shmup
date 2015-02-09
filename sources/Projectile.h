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

#ifndef PROJECTILE_H_DEFINED
#define PROJECTILE_H_DEFINED

#include "SDL.h"
#include "Window.h"
#include "Sprite.h"
#include "MovingEntity.h"

class Projectile : public MovingEntity
{
public:
	Projectile(Sprite *sprite, SDL_Rect hitbox, int speed, int angle);
	~Projectile();
	
	void update();
	void render();

private:
	int speed;
	int angle;
};

#endif //__PROJECTILE_H_DEFINED__