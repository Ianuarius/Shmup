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
#include "EntityCollection.h"
#include "Projectile.h"

class Player : public DamageableEntity, public MovingEntity
{
public:
	Player(Window *window, HUD *hud, EntityCollection<Projectile> *projectiles);
	~Player();

	void update();
	void render();
	
	void immunity(int length);
	bool isImmune();

	virtual int getX() {return MovingEntity::getX(); };
	virtual int getY() {return MovingEntity::getY(); };
private:
	Window *window;
	Animation* currentAnimation;

	/// All possible animations, ready to be selected.
	std::vector<Animation*> animations;

	static SDL_Rect hitbox;
	HUD *hud;
	EntityCollection<Projectile> *projectiles;
	Texture *ammus;
	bool immune, norender, shot;
	int immunityLength;
};

#endif //__PLAYER_H_DEFINED__