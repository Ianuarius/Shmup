/*
 * Player.h
 * 
 * T�ss� luokassa kuvataan pelaaja.
 * 
 * Esimerkki:
 *		Player player = new Player();
 *		player->metodi();
 */

#ifndef PLAYER_H_DEFINED
#define PLAYER_H_DEFINED

#include "SDL.h"
#include "Window.h"
#include "Input.h"
#include "Sprite.h"
#include "DamageableEntity.h"
#include "MovingEntity.h"

class Player : public DamageableEntity, public MovingEntity
{
public:
	Player(Window *window);
	~Player();

	void update();
	virtual void render();

private:
	Animation animation;
	SDL_Rect hitbox;
};

#endif //__PLAYER_H_DEFINED__