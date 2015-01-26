/*
 * DamageableEntity.h
 * 
 * Tämä luokka on yläluokka kaikille entityille, joita voi vahingoittaa, 
 * eli, joilla on health pointit.
 * 
 * Esimerkki:
 *		DamageableEntity damageableEntity = new DamageableEntity();
 *		damageableEntity->metodi();
 */

#ifndef DAMAGEABLEENTITY_H_DEFINED
#define DAMAGEABLEENTITY_H_DEFINED

#include "SDL.h"
#include "Window.h"
#include "Sprite.h"
#include "Entity.h"

class DamageableEntity : public Entity
{
public:
	DamageableEntity();
	~DamageableEntity();

private:
	
};

#endif //__DAMAGEABLEENTITY_H_DEFINED__