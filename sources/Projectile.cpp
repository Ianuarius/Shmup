/*
 * Projectile.cpp
 *
 */

#include "Projectile.h"

Projectile::Projectile(Window *window) : 
	window(window),
	bullet_texture(window, "ammus_sprite.png", 5, 5)
{
	
}

Projectile::~Projectile()
{

}

void Projectile::spawn(int type, int x, int y, int radian)
{

	// Hitbox
	SDL_Rect hb = {1, 1, 2, 2};
	MovingEntity entity(&bullet_texture, hb);

	// Initial X and Yk
	entity.setX(x);
	entity.setY(y);
	entity.speed(20);

	bullet tmp = {entity, type, radian};

	container.push_back(tmp);
}

void Projectile::update()
{
	for (std::vector<bullet>::iterator it = container.begin();
		 it != container.end();
		 ++it) {
	
		int radian = (*it).radian;
		int x = (*it).entity.getX();
		int y = (*it).entity.getY();

		int vx = (*it).entity.getSpeed() * cos(radian);
		int vy = (*it).entity.getSpeed() * sin(radian);

		(*it).entity.setX(x + vx);
		(*it).entity.setY(y + vy);
	}
}

void Projectile::render()
{
	for (std::vector<bullet>::iterator it = container.begin();
		 it != container.end();
		 ++it) {

		(*it).entity.render();
	}
}