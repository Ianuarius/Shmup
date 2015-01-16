/**
 * Text.h
 * 
 * TODO(jouni):
 *   - Private variablet
 *   - Kaikki metodit :D
 *   - Tämä loppuun
 */

#ifndef __TEXT_H_DEFINED__
#define __TEXT_H_DEFINED__

#include <string>
#include "SDL.h"
#include "window.h"
#include "Font.h"
#include "Color.h"

class Text {
	public:
		Text();

		void setFont(Font *font);
		void setColor(Color color);
		void print(Window *window, std::string text);

	private:

};

#endif // __TEXT_H_DEFINED__