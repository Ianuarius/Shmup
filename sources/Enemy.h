/*
 * Enemy.h
 * 
 * Tässä luokassa kuvataan pelaaja.
 * 
 * Esimerkki:
 *		Enemy enemy = new Enemy();
 *		enemy->metodi();
 */

#ifndef __ENEMY_H_DEFINED__
#define __ENEMY_H_DEFINED__

#include "MovingEntity.h"
#include "DamageableEntity.h"
#include "Animation.h"

class Enemy : public MovingEntity, public DamageableEntity
{
	public:
		Enemy(Animation* animation, Animation *dyingAnimation, SDL_Rect hitbox, int initialHitPoints);
		~Enemy();
		void render();
		void update();

		void linearPattern();
		void sinePattern(int index);

	private:
		enum DIRECTION {
			UP,
			DOWN,
			LEFT,
			RIGHT
		};

		Animation *dyingAnimation;

		int index, chilltime;
		bool norender;
		std::vector<int> pattern;
};

#endif //__ENEMY_H_DEFINED__