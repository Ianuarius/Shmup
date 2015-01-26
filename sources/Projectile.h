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
#include "Entity.h"

class Projectile : public Entity
{
public:
	Projectile();
	~Projectile();

private:
	
};

#endif //__PROJECTILE_H_DEFINED__