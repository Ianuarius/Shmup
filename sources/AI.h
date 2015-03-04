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

#include <vector>
#include "Enemy.h"

class AI
{
	public:
		AI(Enemy *enemy);

		void linearPattern();
		void sinePattern();
		void update();

	private:
		Enemy *enemy;

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