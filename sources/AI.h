/*
 * DamageableEntity.h
 * 
 * Tämä luokka on yläluokka kaikille entityille, joita voi vahingoittaa, 
 * eli, joilla on health pointit.
 * 
 * Esimerkki:
 *		DamageableEntity damageableEntity = new DamageableEntity();
 *		damageableEntity->damage(100);
 */

#ifndef __AI_H_DEFINED__
#define __AI_H_DEFINED__

#include <array>
#include "SDL.h"
#include "MovingEntity.h"

class AI
{
	public:
		AI(MovingEntity *entity);

		void linearPattern();
		void sinePattern();
		void update();

	private:
		MovingEntity *entity;

		enum DIRECTION {
			UP,
			DOWN,
			LEFT,
			RIGHT
		};

		int index, chilltime, pattern;
		static const int linear[1];
		static const int sine[6];
};

#endif // __AI_H_DEFINED__