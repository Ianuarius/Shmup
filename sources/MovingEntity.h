/*
 * MovingEntity.h
 * 
 * Tämä luokka on yläluokka kaikille entityille, joita voi vahingoittaa, 
 * eli, joilla on health pointit.
 * 
 * Esimerkki:
 *		MovingEntity movingEntity = new MovingEntity();
 *		movingEntity->metodi();
 */

#ifndef MOVINGENTITY_H_DEFINED
#define MOVINGENTITY_H_DEFINED

#include "SDL.h"
#include "Window.h"
#include "Sprite.h"
#include "Entity.h"

class MovingEntity : public Entity
{
public:
	MovingEntity();
	~MovingEntity();

private:
	
};

#endif //__MOVINGENTITY_H_DEFINED__