/*
 * AI.cpp
 *
 */

#include "AI.h"

AI::AI(Enemy* enemy):
	enemy(enemy),
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

	enemy->move(pattern[index]);
	enemy->move(LEFT);
}