#include "Animation.h"

Animation::Animation(Window *window, Sprite *sprite, int start_frame,
					 int frame_count, int framerate):
					 window(window),
					 animated(sprite),
					 framerate(framerate),
					 current_frame(0),
					 current_frame_time(0)
{
	for (int frame = 0; frame < frame_count; ++frame)
	{
		frames.push_back(frame);
	}
}

Animation::~Animation() {

}

int Animation::getCurrentFrame() {
	return current_frame;
}

int Animation::getFramecount() {
	return frames.size();
}

void Animation::setFramerate(int framerate) {
	this->framerate = framerate;
}

int Animation::getFramerate() {
	return framerate;
}

void Animation::start() {
	running = true;
}

void Animation::pause() {
	running = false;
}

void Animation::render(int x, int y) {
	//printf("frame: %d/%d\n", current_frame, frames.size());
	animated->render(frames[current_frame], x, y);

	if (framerate == 0) {
		return;
	}

	if (!running) {
		return;
	}

	int frametime = (1000 / framerate);
	current_frame_time += window->getDelta();

	if (current_frame_time > frametime) {
		if (current_frame >= (int)frames.size() - 1) {
			current_frame = 0;
		} else {
			current_frame++;
		}

		current_frame_time = 0;
	}
}