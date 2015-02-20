/*
 * Enemy.h
 * 
 * Tässä luokassa kuvataan pelaaja.
 * 
 * Esimerkki:
 *		Enemy enemy = new Enemy();
 *		enemy->metodi();
 */

#ifndef ENEMY_H_DEFINED
#define ENEMY_H_DEFINED

#include "SDL.h"
#include "Window.h"
#include "Sprite.h"
#include "DamageableEntity.h"
#include "MovingEntity.h"

class Enemy : public DamageableEntity, public MovingEntity
{
public:
	Enemy(Animation *animation, SDL_Rect hitbox, int initialHitPoints);
	~Enemy();
	virtual void render();

private:
	
};

#endif //__ENEMY_H_DEFINED__