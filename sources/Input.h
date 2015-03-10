/**
 * Input.h
 * 
 * Input manager.
 * 
 * Esimerkki:
 * // Jossain kohtaa koodia:
 * Input::update();
 *
 * Input::keyState(SDL_SCANCODE_A); // Palauttaa true jos 'A' on alhaalla
 * 
 * TODO(jouni):
 *	- Muunnetaan luokka staattisesta oikeaan oliopohjaiseen
 */

#ifndef __INPUT_H_DEFINED__
#define __INPUT_H_DEFINED__

// Keyboard size
#define KEYBOARD_SIZE 282

// Includet
#include "SDL.h"

class Input {
	public:
		// P‰ivitt‰‰ n‰pp‰imen painallukset
		static void update();

		// Jos n‰pp‰in on alhaalla palauttaa true, muuten false
		static bool keyState(int key);

		// Avustavametodi tarkastamaan onko SHIFT alhalla
		static bool shift();

		// Avustavametodi tarkastamaan onko CTRL alhaalla
		static bool ctrl();

		// Avustavametodi tarkastamaan onko ALT alhaalla
		static bool alt();

		// 'Lukitsee' input managerin. N‰pp‰imi‰ ei p‰ivitet‰, jolloin esim.
		// keyState palauttaa aina false.
		static void lock();

		// Poistaa lukituksen
		static void unlock();

	private:
		// S‰ilytt‰‰ tiedon input managerin lukituksesta
		static bool isLocked;

		// S‰ilytt‰‰ luokan sis‰isesti n‰pp‰inten tilan
		static bool key[KEYBOARD_SIZE];

		// N‰pp‰imistˆn tilan (SDL)
		static const Uint8* keyboard;
};

#endif