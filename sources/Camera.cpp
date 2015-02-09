/*
 * Camera.cpp
 */

#include "Camera.h"

Camera::Camera(int width, int height):
	speed(0)
{
	SDL_Rect realcamera = {0, 0, width, height};
	frame = realcamera;
}

Camera::~Camera()
{
	
}

void Camera::update()
{
	frame.x += speed;
}

void Camera::setSpeed(int speed)
{
	this->speed = speed;
}

int Camera::getSpeed()
{
	return speed;
}

int Camera::getX()
{
	return frame.x;
}