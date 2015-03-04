/**
 *
 * Window.h
 *
 * @todo
 *		- Constant framerate
 *		- Corrected framerate calculation
 */

#ifndef WINDOW_H_DEFINED
#define WINDOW_H_DEFINED

#include <string>
#include "SDL.h"
#include "color.h"
#include "Timer.h"

#define FRAMERATE 30
#define FPS_INTERVAL 1000	// Milliseconds

class Window
{
	public:
		// Constructor
		Window(int width, int height, std::string title, bool fullscreen);
	
		// Destructor & destroy()
		virtual ~Window();
		void destroy();

		void resize(std::string title, int width, int height, bool fullscreen = false);
		void refresh();
		void clear();

		void setTitle(std::string title);

		void minimize();
		void maximize();
		void restore();

		Uint32 getDelta();
		int getFramerate();

		SDL_Renderer* getRenderer();

		// source = Alkuperäisestä kuvasta leikatun alueen sijanti ja koko

		void drawRect(int X, int Y, int W, int H, Color color);
		void fill(Color color);

		unsigned int width; 
		unsigned int height; 
		unsigned int originalWidth;
		unsigned int originalHeight;
	
		//The actual hardware texture
		// SDL_Texture* texture;

	private:
		SDL_Window *window;
		SDL_Surface *surface;
		SDL_Renderer *renderer;
	
		Timer frametimeTimer, fpsTimer;
		Uint32 framerate, frame_delay, current_delta;
		int fps_current, fps;
	
};

#endif //__WINDOW_H_DEFINED__