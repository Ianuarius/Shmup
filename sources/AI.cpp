/*
 * AI.cpp
 *
 */

#include "AI.h"

AI::AI(MovingEntity *entity):
	entity(entity)
{

}

void AI::linearPattern()
{
	std::array<int,1> pattern = {LEFT}; //copy array A into array B
}

void AI::sinePattern()
{
	std::array<int, 6> pattern = {UP, UP, UP, DOWN, DOWN, DOWN};
}


void AI::update()
{
	chilltime = (++chilltime % sizeof(10));
	
	if (chilltime == 0) {
		index = (++index % sizeof(pattern));
		printf("AI: %d\\%d\n", index, sizeof(pattern));
		entity->move(index);
		entity->move(LEFT);
	}

}