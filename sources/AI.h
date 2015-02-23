/*
 * DamageableEntity.h
 * 
 * T�m� luokka on yl�luokka kaikille entityille, joita voi vahingoittaa, 
 * eli, joilla on health pointit.
 * 
 * Esimerkki:
 *		DamageableEntity damageableEntity = new DamageableEntity();
 *		damageableEntity->damage(100);
 */

#ifndef __AI_H_DEFINED__
#define __AI_H_DEFINED__

#include <vector>
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

		int index, chilltime;
		std::vector<int> pattern;
};

#endif // __AI_H_DEFINED__