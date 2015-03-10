#include "Animation.h"

Animation::Animation(Window *window, std::string filename,
					 int width, int height, int start_frame,
					 int frame_count, int framerate):
					 Sprite(window, filename, width, height),
					 window(window),
					 current_frame(0),
					 current_frametime(0),
					 running(true)
{
	setFramerate(framerate);

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
	frametime = (1000 / framerate);
}

void Animation::play(int times) {
	running = true;
	play_count = times;
}

void Animation::pause() {
	running = false;
}

void Animation::render(int x, int y) {
	current_frametime += window->getDelta();

	if (running && play_count != 0)
	{
		if (current_frametime > frametime) {
			if (current_frame >= (int)frames.size() - 1) {
				play_count--;

				if (play_count == 0) {
					running = false;
				}

				current_frame = 0;
			} else {
				current_frame++;
			}

			current_frametime = 0;
		}
	}

	Sprite::setIndex(current_frame);

	if (current_frame != 0 || running) {
		Sprite::render(x, y);
	}
}

bool Animation::done() {
	return (running ? false : true);
}