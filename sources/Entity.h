/*
 * Entity.h
 * 
 * Tämä luokka on yläluokka kaikille pelin entiteeteille, joita voivat olla
 * esimerkiksi, pelaaja, viholliset ja ammukset.
 * 
 * Esimerkki:
 *		Entity entity = new Entity();
 *		entity->metodi();
 */

#ifndef ENTITY_H_DEFINED
#define ENTITY_H_DEFINED

#include "SDL.h"
#include "Window.h"
#include "Sprite.h"

class Entity
{
public:
	Entity();
	~Entity();

private:
	int x;
	int y;

	
};

#endif //__ENTITY_H_DEFINED__