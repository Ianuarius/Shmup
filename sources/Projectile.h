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

#include "SDL.h"
#include "Window.h"
#include "Sprite.h"
#include "MovingEntity.h"

class Projectile //: public MovingEntity
{
public:
	Projectile(std::string filename, int Xspeed, int Yspeed);
	~Projectile();
	
	void update();
	void render();

private:
	int Xspeed, Yspeed;
	//MovingEntity entity;
};

#endif //__PROJECTILE_H_DEFINED__