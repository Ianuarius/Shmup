/*
 * AI.cpp
 *
 */

#include "AI.h"

AI::AI(MovingEntity *entity):
	entity(entity),
	index(0)
{ }

void AI::linearPattern()
{
	int linear[] = {LEFT};
	pattern.assign(linear, linear+1);
}

void AI::sinePattern()
{
	int sine[] = {UP, UP, UP, DOWN, DOWN, DOWN};
	pattern.assign(sine, sine+6);
}


void AI::update()
{
	chilltime = (++chilltime % 5);

	if (chilltime == 0) {
		index = (++index % pattern.size());
	}

	entity->move(pattern[index]);
	entity->move(LEFT);
}