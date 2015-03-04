/*
 * HUD.h
 * 
 * HUDissa n‰ytet‰‰n aseet, upgradet, nyk. score, highscore, suojien m‰‰r‰ jne  
 *
 * Esim.
 *
 * HUD Hud(&window)
 * Hud.render();
 * 
 * Jos halutaan piilottaa:
 * Hud.hide();
 *
 * Jos peli antaa pisteit‰:
 * Hud.setScore(10);
 *
 */

#ifndef HUD_H_DEFINED
#define HUD_H_DEFINED

#include "Font.h"
#include "Text.h"
#include "Texture.h"
#include "Sprite.h"
#include "Window.h"

class HUD
{
public:
	HUD(Window *window);
	~HUD();
	
	Sprite *weapon;
	
	void setWeapon(int weaponId);
	void setScore(int score);

	void render();
	void show();
	void hide();

protected:
	
	Text score;
	Text highscore;

	Text numberScore;
	Text numberHighscore;

	Font font;
	Color text_color;

	bool isHidden;

	int currentScore;
	int highScore;

	Window *window;

	Texture weapons;
	Sprite selected_weapon;
	int weapon_index;
};

#endif //__HUD_H_DEFINED__