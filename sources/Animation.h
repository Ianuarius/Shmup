#ifndef __ANIMATION_H_INCLUDED__
#define __ANIMATION_H_INCLUDED__

#include <vector>
#include "Sprite.h"

class Animation
{
	public:
		Animation(Window *window, Sprite *sprite, int start_frame,
				  int frame_count, int framerate);
		virtual ~Animation();

		void addFrame(int frame_index);
		void setFramerate(int framerate);

		int getFramecount();
		int getFramerate();
		int getCurrentFrame();

		void render(int x, int y);

		void start();
		void pause();

	private:
		Window *window;
		Sprite *animated;

		std::vector<int> frames;
		int framerate, current_frame, current_frame_time;
		bool running;
};

#endif // __ANIMATION_H_INCLUDED__
