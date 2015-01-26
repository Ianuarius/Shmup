/*
 * Player.h
 * 
 * Tässä luokassa kuvataan pelaaja.
 * 
 * Esimerkki:
 *		Player player = new Player();
 *		player->metodi();
 */

#ifndef PLAYER_H_DEFINED
#define PLAYER_H_DEFINED

#include "SDL.h"
#include "Window.h"
#include "Sprite.h"
#include "DamageableEntity.h"
#include "MovingEntity.h"

class Player : public DamageableEntity, public MovingEntity
{
public:
	Player();
	~Player();

private:
	
};

#endif //__PLAYER_H_DEFINED__