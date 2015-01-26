/*
 * PowerUp.h
 * 
 * Tämä luokka on yläluokka kaikille entityille, joita voi vahingoittaa, 
 * eli, joilla on health pointit.
 * 
 * Esimerkki:
 *		PowerUp movingEntity = new PowerUp();
 *		movingEntity->metodi();
 */

#ifndef POWERUP_H_DEFINED
#define POWERUP_H_DEFINED

#include "SDL.h"
#include "Window.h"
#include "Sprite.h"
#include "Entity.h"

class PowerUp : public Entity
{
public:
	PowerUp();
	~PowerUp();

private:
	
};

#endif //__POWERUP_H_DEFINED__