/*
 * DamageableEntity.cpp
 *
 */

#include "DamageableEntity.h"

DamageableEntity::DamageableEntity(int initialHitPoints):
	isAlive(true),
	hitpoints(initialHitPoints)
{
}

DamageableEntity::~DamageableEntity()
{
}

void DamageableEntity::heal(int amount)
{
	hitpoints += amount;
}

void DamageableEntity::damage(int amount)
{
	hitpoints -= amount;

	if (hitpoints <= 0)
	{
		hitpoints = 0;
		isAlive = false;
	}
}

bool DamageableEntity::isDead()
{
	if (isAlive == true)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int DamageableEntity::getHitpoints()
{
	return hitpoints;
}