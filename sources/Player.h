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
#include "HUD.h"

class Player : public DamageableEntity, public MovingEntity
{
public:
	Player(Window *window, HUD *hud);
	~Player();

	void update();
	virtual void render();

	virtual int getX() {return MovingEntity::getX(); };
	virtual int getY() {return MovingEntity::getY(); };
	

private:
	Animation animation;
	SDL_Rect hitbox;
	HUD *hud;
};

#endif //__PLAYER_H_DEFINED__