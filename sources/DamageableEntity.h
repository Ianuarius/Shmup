/*
 * DamageableEntity.h
 * 
 * T‰m‰ luokka on yl‰luokka kaikille entityille, joita voi vahingoittaa, 
 * eli, joilla on health pointit.
 * 
 * Esimerkki:
 *		DamageableEntity damageableEntity = new DamageableEntity();
 *		damageableEntity->damage(100);
 */

#ifndef DAMAGEABLEENTITY_H_DEFINED
#define DAMAGEABLEENTITY_H_DEFINED

#include "SDL.h"
#include "Window.h"
#include "Sprite.h"
#include "Entity.h"

class DamageableEntity
{
public:
	DamageableEntity(int initialHitPoints);
	~DamageableEntity();

	// Parantaa entity‰ jonkin m‰‰r‰n
	void heal(int amount);

	// Aiheuttaa vahinkoa entityyn tietyn m‰‰r‰n
	void damage(int amount);

	bool isDead();

	int getHitpoints();

private:
	bool alive;
	int hitpoints;
};

#endif //__DAMAGEABLEENTITY_H_DEFINED__